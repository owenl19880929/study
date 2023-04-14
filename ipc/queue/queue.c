#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define QUEUE_LEN_MAX 16
#define USER_DATA_SIZE 128

typedef struct node{
    void* data;
    struct node* next;
} node_t;

typedef struct queue{
    node_t* front;
    node_t* rear;
    int queue_len;
    int max_len;
    pthread_mutex_t mutex;
    pthread_cond_t  cond_wait_enqueue;
    pthread_cond_t  cond_wait_dequeue;
} queue_t;

typedef struct thread_data{
    queue_t main2thread;
    queue_t thread2main;
} thread_data_t;


int thread_exit;

pthread_mutex_t mutex_thread2main;
pthread_cond_t  cond_thread2main;

static int queue_init(queue_t *queue, int max_len) {

    if (queue == NULL || max_len == 0) {
        printf("%s %d invalid queue param!\n", __func__, __LINE__);
        return -1;
    }

    queue->front = queue->rear = NULL;
    queue->max_len = max_len;
    queue->queue_len = 0;

    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond_wait_dequeue, NULL);    
    pthread_cond_init(&queue->cond_wait_enqueue, NULL);  

    return 0;
}

static int queue_uninit(queue_t *queue) {

    if (queue == NULL) {
        printf("%s %d invalid queue param!\n", __func__, __LINE__);
        return -1;
    }

    queue->front = queue->rear = NULL;
    queue->max_len = 0;
    queue->queue_len = 0;

    pthread_mutex_destroy(&queue->mutex);
    pthread_cond_destroy(&queue->cond_wait_dequeue);    
    pthread_cond_destroy(&queue->cond_wait_enqueue);
  
    return 0;
}

static int queue_empty(queue_t *queue) {

    int is_empty = 0;

    if (queue == NULL) {
        printf("%s %d invalid queue param!\n", __func__, __LINE__);
        return -1;
    }

    is_empty =  queue->queue_len ? 0 : 1;

    return is_empty;
}

static int queue_full(queue_t *queue) {

    int is_full = 0;

    if (queue == NULL) {
        printf("%s %d invalid queue param!\n", __func__, __LINE__);
        return -1;
    }

    if (queue->queue_len != 0 && queue->queue_len == queue->max_len) {
        is_full = 1;
    } else {
        is_full = 0;
    }

    return is_full;
}

static int queue_push(queue_t *queue, node_t *node) {

    if (queue == NULL || node == NULL) {
        printf("%s %d invalid queue param!\n", __func__, __LINE__);
        return -1;
    }

    pthread_mutex_lock(&queue->mutex);

    if (queue_full(queue)) {
        
        while(queue_full(queue)) {

            pthread_cond_wait(&queue->cond_wait_dequeue, &queue->mutex);

        }

    }

    if (queue->front == NULL) {

        queue->front = queue->rear = node;

    } else {

        queue->rear->next = node;
        queue->rear = node;

    }

    queue->queue_len++;

    pthread_mutex_unlock(&queue->mutex);

    pthread_cond_signal(&queue->cond_wait_enqueue);

    return 0;
}

static int queue_pop(queue_t *queue, node_t** node ) {

    if (queue == NULL || node == NULL) {
        printf("%s %d invalid queue param!\n", __func__, __LINE__);
        return -1;
    }

    pthread_mutex_lock(&queue->mutex);

    if (queue_empty(queue)) {
        
        while(queue_empty(queue)) {

            pthread_cond_wait(&queue->cond_wait_enqueue, &queue->mutex);

        }

    }

    *node = queue->front;
    queue->front = queue->front->next;

    queue->queue_len--;

    pthread_mutex_unlock(&queue->mutex);

    pthread_cond_signal(&queue->cond_wait_dequeue);

    return 0;
}

static node_t* alloc_node(void) {

    node_t* new_node = (node_t*)calloc(1, sizeof(node_t));

    if (new_node == NULL) {
        printf("%s %d alloc node failed!\n", __func__, __LINE__);
        return NULL;
    }

    new_node->data = calloc(1, USER_DATA_SIZE);
    new_node->next = NULL;

}

static int destroy_node(node_t** node) {

    node_t* old_node = NULL;

    if (node == NULL || *node == NULL) {
        printf("%s %d invalid param!\n", __func__, __LINE__);
        return -1;
    }

    old_node = *node;

    if (old_node->data) {
        free(old_node->data);
        old_node->data = NULL;
    }

    free(old_node);
    node = NULL;

    return 0;
}

static void* process_thread(void* arg) {

    int ret = 0, counter = 0;
    node_t* node = NULL;
    thread_data_t *thread_data = NULL;
    char data[USER_DATA_SIZE];

    thread_data = (thread_data_t*)arg;

    while (!thread_exit)
    {
        // 1. push a node from queue, if queue is full, then wait;
        node = alloc_node();
        while (node == NULL) {
            printf("%s %d alloc a new node failed!, try again\n", __func__, __LINE__);
            usleep(1000*1000);
            node = alloc_node();
        }

        snprintf(data, USER_DATA_SIZE, "Thread current num is %d", counter++);
        memcpy(node->data, data, USER_DATA_SIZE);
        printf("thread produce msg : %s\n", (char*)node->data);
        usleep(1000*1000);


        ret = queue_push(&thread_data->thread2main, node);
        if (ret) {
            printf("%s %d failed to push node to queue, exit\n", __func__, __LINE__);
            return NULL;
        }

    }
    printf("thread exit\n");
    return NULL;
}

int main(char** argv, int argc) {

    int ret = 0, i;
    thread_data_t* thread_data = NULL; 
    pthread_t thread_id = 0;
    node_t* node = NULL;
    char data[USER_DATA_SIZE];
    int counter = 0;

    thread_data = (thread_data_t*)calloc(1, sizeof(thread_data_t));
    if (thread_data == NULL) {
        printf("%s %d alloc thread_data failed!\n", __func__, __LINE__);
        return -1;
    }

    queue_init(&thread_data->thread2main, QUEUE_LEN_MAX);

    ret = pthread_create(&thread_id, NULL, process_thread, thread_data);
    if (ret) {
        printf("%s %d pthread create failed!\n", __func__, __LINE__);
        return -1;
    }

    while (!thread_exit)
    {

        // 1. get a node from queue, if queue is empty, then wait;

        ret = queue_pop(&thread_data->thread2main, &node);
        if (ret) {
            printf("%s %d failed to pop node from queue, exit\n", __func__, __LINE__);
            thread_exit = 1;
            break;
        }
        // 2. process node data
        printf("main receive msg : %s\n", (char*)node->data);
        usleep(100*1000);
        // 3. destroy node
        destroy_node(&node);

    }

    pthread_join(thread_id, NULL);

    queue_uninit(&thread_data->thread2main);

    free(thread_data);

    printf("main thread exit\n");

    return 0;
}

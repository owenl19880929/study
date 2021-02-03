#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node{
    int data;
    struct list_node* next;
}list_node;

bool initListHead(list_node** list_head){

    if(list_head == NULL){
        return false;
    }	

    if(*list_head != NULL){
        return true;
    }

    *list_head = (list_node*)malloc(sizeof(list_node));
    if(*list_head == NULL){
        return false;
    }
    (*list_head)->data = 0;
    (*list_head)->next = NULL;

    return true;
}

bool addNodeTail(list_node* list_head, int val){
    if(list_head == NULL){
        return false;
    }

    list_node* new_node = (list_node*)malloc(sizeof(list_node));
    if(new_node == NULL){
        return false;
    }
    new_node->data = val;
    new_node->next = NULL;

    list_node* current = list_head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = new_node;

    return true;
}

bool addNodeHead(list_node* list_head, int val){
    if(list_head == NULL){
        return false;
    }

    list_node* new_node = (list_node*)malloc(sizeof(list_node));
    if(new_node == NULL){
        return false;
    }
    new_node->data = val;
    new_node->next = list_head->next;
    
    list_head->next = new_node;
    return true;
}


bool deleteNodeHead(list_node* list_head){
    if(list_head == NULL || list_head->next == NULL){
        return false;
    }

    list_node* delete_node = list_head->next;
    list_head->next = list_head->next->next;

    free(delete_node);
    return true;
}

bool deleteNodeTail(list_node* list_head){
    if(list_head == NULL || list_head->next == NULL){
        return false;
    }

    list_node* pre  = list_head;
    list_node* current = list_head->next;
    while(current != NULL && current->next != NULL){
	pre = pre->next;
        current = current->next;
    }

    free(current);
    pre->next = NULL;

    return true;
}

void printList(list_node* list_head){
    if(list_head == NULL){
        return;
    }

    list_node* current = list_head->next;
    while(current != NULL){
        printf("%d-", current->data);
	current = current->next;
    }
    printf("\n");
}

int main(int argc, char* argv){
    printf("main start\n");    
    list_node* list_head = NULL;
    initListHead(&list_head);
    addNodeTail(list_head, 1);
    addNodeTail(list_head, 2);
    addNodeTail(list_head, 3);
    addNodeTail(list_head, 4);
    addNodeTail(list_head, 5);
    printList(list_head);

    deleteNodeHead(list_head);
    printList(list_head);
    deleteNodeHead(list_head);
    printList(list_head);

    addNodeHead(list_head, 2);
    printList(list_head);
    addNodeHead(list_head, 1);
    printList(list_head);

    deleteNodeTail(list_head);
    printList(list_head);

    deleteNodeTail(list_head);
    printList(list_head);

    deleteNodeTail(list_head);
    printList(list_head);

    deleteNodeTail(list_head);
    printList(list_head);

    deleteNodeTail(list_head);
    printList(list_head);

    deleteNodeTail(list_head);
    printList(list_head);

    addNodeTail(list_head, 1);
    addNodeTail(list_head, 2);
    addNodeTail(list_head, 3);
    addNodeTail(list_head, 4);
    addNodeTail(list_head, 5);
    printList(list_head);

    return 0;
}


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
}NODE;

//Create a List;
NODE* InitList(void)
{
    NODE* headNode = (NODE*)malloc(sizeof(NODE));
    if(NULL == headNode)
    {
	printf("Alloc new list head failed\n");
        return NULL;
    }
    
    NODE* list = headNode;
    int list_length = 0;
    printf("Please input the length of list:\n");
    scanf("%d", &list_length);

    //int lsit_length = 0;
    int value = 0;
    int index = 0;
    for(index= 0; index < list_length; index++)
    {
        NODE* newNode = (NODE*)malloc(sizeof(NODE));
        if(NULL == newNode)
        {
            printf("Alloc new node failed\n");
            return NULL;
        }
        else
        {
	    printf("please input the val of the %dth element:", index);	
	    scanf("%d", &value);
	    newNode->data = value;
	    newNode->next = NULL;
	    headNode->next = newNode;
	    headNode = headNode->next;
        }
    }
    
    return list;
}

//List node data
bool ListNode(NODE* headNode)
{
    if(NULL == headNode)
    {
         printf("Error: the list is NULL!\n");
         return false;
    }
    
    NODE* p = headNode->next;
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p = p->next;   
    }

    return true;
}

bool InsertNode2Head(NODE* headNode, int value)
{
    if(headNode ==NULL)
    {
        printf("Error: headNode or newNode is NULL\n");
        return false;
    }
    
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if(NULL == newNode)
    {
        printf("Alloc new node failed\n");
        return false;
    }

    newNode->data = value;

    newNode->next = headNode->next;
    headNode->next = newNode;
    return true; 
}

//Insert a Node to the list;
bool InsertNode(NODE* headNode, int value, int index)
{
    if(headNode == NULL)
    {
	printf("Error: headNode or newNode is NULL\n");
        return false;
    }
    
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if(NULL == newNode)
    {
         printf("Error: Allocate the new Node failed!\n");
         return false;
    }
    newNode->data = value;    
    
    int i = 1;
    NODE* p = headNode;
    while((p != NULL) && (i < index))
    {
            p = p->next;
            i++;
    }
    
    if(p == NULL)
    {
	printf("Error: not found the pos:%d\n", index);
	return false;
    }    
    
    newNode->next = p->next;
    p->next = newNode;

    return true;
}
//Del a Node from the list
bool DeleteNode(NODE* head, int index, int* val)
{
    if(head == NULL)
    {
        printf("Error: the list is NULL\n");
	return false;
    }

    int i = 1;
    NODE* p = head->next;
    while((p!=NULL) && (i < index))
    {
	head = head->next;
        p = p->next;
        i++;
    }

    if(p == NULL)
    {
	printf("Error: not find the node pos=%d\n", index);
	return false;
    }
    
    *val = p->data;
    head->next = p->next;
    free(p);
    p = NULL;
    
    printf("Success to delete node  pos=%d, value=%d\n", index, *val);
    return true;
}

void SortList(NODE* head)
{

}


void main(int argc, char* argv)
{
    printf("test1\n");
    NODE* list = InitList();
    if(NULL == list)
        exit -1;
    else
        ListNode(list);  
    int value, index;
    //printf("Please input the value:");
    //scanf("%d", &value);
    //printf("Please input the index:");
    //scanf("%d", &index);
    //InsertNode(list, value, index); 
    //ListNode(list);  
    
    printf("Please input the value to insert header:");
    scanf("%d", &value);
    InsertNode2Head(list, value);  
    ListNode(list);

    printf("Please input the index of node to remove:");
    scanf("%d", &index);
    DeleteNode(list, index, &value);
    ListNode(list);
}

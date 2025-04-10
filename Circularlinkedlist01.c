
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct CircularLinkedList
{
    struct Node* head;
};

struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)
    malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void display(struct CircularLinkedList* list)
{
    struct Node* temp=list->head;
    do 
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }while(temp!=list->head);
    printf("(back to head)\n");
}
int main()
{
    struct CircularLinkedList C;
    C.head=NULL;
    
    struct Node* n=createNode(10);
    C.head=n;
    
    struct Node* n1=createNode(20);
    n->next=n1;
    
    struct Node* n2=createNode(30);
    n1->next=n2;
    
    struct Node* n3=createNode(40);
    n2->next=n3;
    
    n3->next=C.head;
    display(&C);
}

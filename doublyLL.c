#include<stdio.h>
#include<stdlib.h>
void create();
typedef struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
void display(Node *);
Node *head,*newNode,*temp;
int size=0;
 void create(){
    int ch;
    head=NULL;
     ch=1;
     while(ch){
      newNode=( Node*)malloc(sizeof(Node));// creating nodes
       printf("\n Enter data of the Node \n");

      scanf("%d",&newNode->data);
      newNode->next=NULL;
      newNode->prev=NULL;
      if(head==NULL){
          head=temp=newNode;
      }
      else{
          temp->next=newNode;
          newNode->prev=temp;
          temp=newNode;
      }
      printf("\n\n\nPress 1 to continue  and 0 to discontinue:\n\n\n");
        scanf("%d", &ch);
     } 
    }
    int main(){
    create();
    display(head);

    return 0;
}
void insertAtEnd(int val){
      Node *node,*temp;
    node=(Node *)malloc(sizeof(Node));
    node->data=val;
    node->prev=NULL;
    node->next=NULL;
    if(head==NULL){
        head=node;
    }
    else{
          temp->next=newNode;
          newNode->prev=temp;
          temp=newNode;
      }
}
void insertAtstart(int val){
    Node *node;
    node=(Node *)malloc(sizeof(Node));
    node->data=val;
    node->prev=NULL;
    node->next=NULL;
    if(head==NULL){
        head=node;
    }
    else{
        node->next=head;
        head->prev=node;
        head=node;
    }
    size++;
}
void insertAtIdx(int val,int idx){
    if(idx==0){
        insertAtstart(val);
        return;
    }
    else if(idx==size){
      insertAtEnd(val);
    }
    else{
        Node *temp=head;
        Node *node;
        node=(Node *)malloc(sizeof(Node));
        node->data=val;
        node->prev=NULL;
        node->next=NULL;
        for(int i=0;i<idx-1;i++){
            temp=temp->next;
        }
        node->next=temp->next;
        temp->next=node;
        node->prev=temp;
        size++;
    }
}

    
void display(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        printf("%d <->",temp->data);
        temp=temp->next;
        
    }
    printf("END\n");
}

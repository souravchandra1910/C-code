#include <stdio.h>
#include <stdlib.h>
void insertAtFirst(int);

void insertAtEnd(int);
void insertAtIndex(int,int);
void delAtStart();
void delAtEnd();
void delAtInd(int);
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
 Node *head;
 int size=0;
 void display(Node *);
int main()
{
      Node *newNode,*temp;
     head=NULL;
     int ch=1;
     while(ch){
      newNode=( Node*)malloc(sizeof(Node));// creating nodes
       printf("\n Enter data of the Node \n");
       
      scanf("%d",&newNode->data);
      newNode->next=NULL;
      if(head==NULL){
          head=temp=newNode;
      }
      else{
          temp->next=newNode;
          temp=newNode;
      }
      printf("\n\n\nPress 1 to continue  and 0 to discontinue:\n\n\n");
        scanf("%d", &ch);
     }
    display(head);
    insertAtFirst(5);
    display(head);
    insertAtEnd(50);
    display(head);
    insertAtIndex(40,4);
    display(head);
    delAtStart();
    display(head);
    delAtEnd();
    display(head);
    delAtInd(2);
    display(head);
    reverse();
    display(head);

 
    return 0;
}

void display(Node *head){
     Node *temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("END\n");
    

    
}

void insertAtFirst(int val){
    Node *node;
 node=( Node*)malloc(sizeof( Node));
  node->data=val;
  node->next=NULL;
    if(head==NULL){
      head=node;
  }
  else{
      node->next=head;
      head=node;
  }
  size++;
}
void insertAtEnd(int val){
    Node *node,*temp;
 node=( Node*)malloc(sizeof( Node));
  node->data=val;
  node->next=NULL;
    if(head==NULL){
      head=node;
  }
  else{
      temp=( Node*)malloc(sizeof( Node)); 
      temp=head;
      while(temp->next!=NULL){
          temp=temp->next;
      }
      temp->next=node;
  }
  size++;
}

void insertAtIndex(int val,int idx){
    Node *node,*temp;
    node=(Node *)malloc(sizeof(Node));
    node->data=val;
    node->next=NULL;
    if(head==NULL){
        insertAtFirst(val);
    }
    else if(idx==size){
        insertAtEnd(val);
    }
    else{
        temp=head;
        for (int i = 0; i < idx-1; i++)
        {
            temp=temp->next;
        }

        node->next=temp->next;
        temp->next=node;
        size++;
    }
}

    void delAtStart(){
        Node *temp;
        if(head==NULL){
            printf("The List is Empty:");
        }
        else{
            temp=head;
            head=head->next;
            size--;
        }
        free(temp);
    }
    void delAtEnd(){
        Node *temp,*temp1;
        if(head==NULL){
            printf("list is empty");
            return;
        }
        else if(head->next==NULL){
            temp=head;
            head=head->next;
            free(temp);
            size--;
        }
        else{
          temp=head;
          while(temp->next->next!=NULL){
              temp=temp->next;
          }
          temp1=temp->next->next;
          temp->next=NULL;
          free(temp1);
          size--;
        }
    }

    void delAtInd(int idx){
         Node *node,*temp;
         if(head==NULL){
             printf("The list is empty\n");
             return;
         }
        if(idx==0){
            delAtStart();
        }
        else if(idx==size-1){
            delAtEnd();
        }
        else{
           node =head;
            for(int i=0;i<idx-1;i++){
                node=node->next;
            }
            temp=node->next;
            node->next=node->next->next;
            free(temp);
            size--;
        }
    }
    void reverse(){
        Node *curr,*prev,*next;
        curr=head;
        prev=NULL;
        next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }

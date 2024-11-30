#include<stdio.h>
#include<stdlib.h>
struct node
{
   struct node *prev;
   int data;
   struct node *next;

};

struct node *addatempty(struct node *head,int data){
  struct node *temp = malloc(sizeof(struct node));
 temp->prev=NULL;
 temp->data=data;
 temp->next=NULL;
 head=temp;
 return head;
}
struct node *addatbeg(struct node *head,int data){
    struct node *temp =malloc(sizeof(struct node));
temp->prev=NULL;
 temp->data=data;
 temp->next=NULL;

 temp->next=head;
 head->prev=temp;
head=temp;
 return head;
 
}
struct node *addatend(struct node *head,int data){
    struct node *temp =malloc(sizeof(struct node));
    struct node *temp2 ;
temp->prev=NULL;
 temp->data=data;
 temp->next=NULL;
temp2=head;
while (temp2->next!=NULL)
{
   temp2=temp2->next;
}

 temp2->next=temp;
 temp->prev=temp2;
  head=temp;
 return head;
 
}
//struct nodes *addatpos(struct nodes *head,int data,int position){



int main(){
    struct node *head=malloc(sizeof(struct node));
  
    head=addatempty(head,55);
    printf("%d",head->data);
    head=addatbeg(head,65);
    printf("%d\n",head->data);
    head=addatend(head,69);
    printf("%d\n",head->data);
    
    
    
    
}
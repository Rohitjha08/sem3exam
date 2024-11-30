#include <stdio.h>
#include<stdlib.h>
//creating anode
struct node
{
    int data;
    struct node *link;

};
void countnodes(struct node *head){
    struct node *ptr=NULL;
    int count=0;
    ptr=head;
    while(ptr != NULL){//last pointer
        count++;
        ptr=ptr->link;
        
    }
    printf(" COUNT IS %d",count);
}
void printdata(struct nodes *head){
    struct node *ptr=NULL;
     ptr=head;
     while(ptr != NULL){//last pointer
      printf(" %d",ptr->data);
        ptr=ptr->link;
        
    }
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=63;
    current->link=NULL;
    head->link=current;
     struct node *current2=malloc(sizeof(struct node));
    current2->data=73;
    current2->link=NULL;
    current->link=current2;
    countnodes(head);
    printdata(head);
    return 0;

    
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;

} *top = NULL;

void push(int data) {
    struct node *newnode =NULL;
    newnode=  malloc(sizeof(newnode));
    newnode ->data= data;
    newnode ->link=NULL;
    newnode->link=top;
    top=newnode;



}
int pop(){
    struct node *temp;
    temp=top;
    int val=temp->data;
    top=top->link;


    free(temp);
    temp=NULL;
    return val;



}
int empty(){
    if(top==NULL){
        return 1;
    }
    else return 0;

}
int peek(){
    if(empty()){
        exit(1);

    }
    else return top->data;

}
void print(){
    struct node *temp;
    temp=top;
    while(temp){
        printf("%d",temp->data);
        temp=temp->link;

    }
 printf("\n");
}
int main(){
    int choice,data;
    while(1){
        printf("menu");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("enter the element to be pushed");
             scanf("%d",&data);
             push(data);

            break;
        case 2:data=pop();
        case 3:data=peek();  
        
        default:
            break;
        }
    }
}

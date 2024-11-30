#include <stdio.h>
#include <stdlib.h>
//queue impleementation
#define MAX 100

int stack_arr[MAX];
int top=-1;
void push(int x);
void pop();
void push(int x){
    if(top==MAX-1){
        printf("stack overflow");
    }
    else{
    top = top+1;
    stack_arr[top]=x;

    }
    

}
void pop(){
    if(top==-1){
        printf("stack overflown");

    }
    int temp;
    temp=stack_arr[top];
    top=top-1;
    printf("popped element is %d \n ",temp);

    
}
int main(){
    int ch;
    while(1){
        printf("1 2 3 4 1 push 2 pop 3 topelement 4 display 5 ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:printf("enter the element to be pushed ");
                   int x;
               scanf("%d",&x);
               push(x);
            break;
         case 2:pop();
               
                  
            break;
        
        default:
            break;
        }
    }
}


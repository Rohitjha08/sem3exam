#include <stdio.h>
#include<stdlib.h>
//creating anode
struct node
{
    int data;
    struct node *link;

};
struct node *addatbeg(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        // Memory allocation failed
        return head;
    }
    temp->data = data;
    temp->link = head;
    head=temp;
    return head;
}
struct node *addatend(struct node * head,int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;


    struct node *ptr=head;
    while(ptr!=NULL){
        ptr=ptr->link;

    }
ptr->link=temp;
return head;

}
/*truct node *addatpos(head,int data,int pos){


}*/

int main() {
    struct node *head = NULL;
    head = addatbeg(head, 32);
    head = addatbeg(head, 69);
    head = addatbeg(head, 6);
    head = addatbeg(head, 6);
    head = addatend(head,22);


    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }    printf("\n");

    return 0;
}
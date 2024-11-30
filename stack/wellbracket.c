//algorithm for this
//create an empty stavk

//2nd scan all the element left to right 
//3rd step if the symbol is left bracket push that into stack
//if symbol is right bracket then 
//2 case first is checck if stack is empty
//else pop an element into stack
//if the popped bracket doesnt match with right bracket then invalid expression mismatched bracket
//after scanning all the symbol print valid expression if stack is empty or else print inavlid expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack_arr[MAX]


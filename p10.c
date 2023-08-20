#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int data;
struct node *next;
} Node;
Node *top = NULL;
void push(int data) {
Node *newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->next = top;
top = newNode;
}
int pop() {
if (top == NULL) {
printf("\nStack is empty\n");
return INT_MIN;
}
Node *temp = top;
top = top->next;
int data = temp->data;
free(temp);
return data; 
}
void display() {
if(top==NULL){
printf("\nStack is Empty!!!\n");
return; 
}
printf("\nStack elements: ");
Node* ptr=top; 
while(ptr!=NULL){
printf("%d ",ptr->data);
ptr=ptr->next; 
}
}
int main() {
int choice, value;
while(1){
printf("\n\n***** MENU *****\n");
printf("1. Push\n2. Pop\n3. Display\n4. Exit");
printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1: 
printf("Enter the value to be pushed: ");
scanf("%d", &value);
push(value);
break;
case 2: 
value=pop();
if(value!=INT_MIN)
printf("\nThe popped value is : %d",value);
break;
case 3: 
display();
break;
case 4:
exit(0);
default:
printf("\nWrong selection!!! Please try again!!!\n");
}
}
}

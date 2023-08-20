#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct {
int data;
int isEmpty;
} QueueElement;
QueueElement queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int data) {
if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) 
{
printf("\nQueue is full\n");
return;
} else if (front == -1) {
front = rear = 0;
queue[rear].data = data;
queue[rear].isEmpty = 0;
} else if (rear == MAX - 1 && front != 0) {
rear = 0;
queue[rear].data = data;
queue[rear].isEmpty = 0;
} else {
rear++;
queue[rear].data = data;
queue[rear].isEmpty = 0;
}
}
int dequeue() {
if (front == -1) {
printf("\nQueue is empty\n");
return INT_MIN;
}
int data = queue[front].data;
QueueElement emptyElement = { .data=0, .isEmpty=1 };
queue[front] = emptyElement;
if (front == rear) {
front = -1;
rear = -1;
} else if (front == MAX - 1)
front = 0;
else
front++;
return data; 
}
void display() {
if(front==-1){
printf("\nQueue is Empty!!!\n");
return; 
}
printf("\nQueue elements: ");
if(rear>=front){
for(int i=front;i<=rear;i++)
printf("%d ",queue[i].data);
}
else{
for(int i=front;i<MAX;i++)
printf("%d ",queue[i].data);
for(int i=0;i<=rear;i++)
printf("%d ",queue[i].data);
}
}
int main() {
int choice, value;
for(int i=0; i<MAX; i++){
QueueElement emptyElement={.data=0,.isEmpty=1};
queue[i]=emptyElement; 
}
while(1){
printf("\n\n***** MENU *****\n");
printf("1. Insert\n2. Delete\n3. Display\n4. Exit");
printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1: 
printf("Enter the value to be insert: ");
scanf("%d", &value);
enqueue(value);
break;
case 2: 
value=dequeue();
if(value!=INT_MIN)
printf("\nThe number deleted is : %d",value);
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

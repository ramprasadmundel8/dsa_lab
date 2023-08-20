#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int data) {
if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) 
{
printf("\nQueue is full\n");
return;
} else if (front == -1) {
front = rear = 0;
queue[rear] = data;
} else if (rear == MAX - 1 && front != 0) {
rear = 0;
queue[rear] = data;
} else {
rear++;
queue[rear] = data;
}
}
int dequeue() {
if (front == -1) {
printf("\nQueue is empty\n");
return -1;
}
int data = queue[front];
queue[front] = -1;
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
if (front == -1) {
printf("\nQueue is empty\n");
return;
}
printf("\nPhone calls in the Queue: ");
if (rear >= front)
for(int i=front; i<=rear; i++)
printf("%d ",queue[i]);
else{
for(int i=front; i<MAX; i++)
printf("%d ",queue[i]);
for(int i=0; i<=rear; i++)
printf("%d ",queue[i]);
}
}
int main() {
int choice, value;
while(1){
printf("\n\n***** MENU *****\n");
printf("1. Add Phone Call\n2. Remove Phone Call\n3. Display Queue\n4. 
Exit");
printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1: 
printf("Enter the phone call number: ");
scanf("%d", &value);
enqueue(value);
break;
case 2: 
value=dequeue();
if(value!=-1)
printf("\nThe phone call number %d has been removed from the 
Queue.",value);
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

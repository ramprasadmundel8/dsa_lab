#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int data;
struct node *prev;
struct node *next;
} Node;
Node *head = NULL;
void insert(int data, int key) {
Node *newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->prev = NULL;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
return;
}
Node* current=head; 
while(current!=NULL && current->data!=key)
current=current->next; 
if(current==NULL){
printf("\nKey not found\n");
return; 
}
newNode->prev=current->prev; 
current->prev=newNode; 
newNode->next=current; 
if(newNode->prev!=NULL)
newNode->prev->next=newNode; 
else
head=newNode; 
}
void delete(int data) {
if(head==NULL){
printf("\nList is empty\n");
return; 
}
Node* temp=head,*prev=NULL,*next=NULL; 
while(temp!=NULL && temp->data!=data){
prev=temp;
temp=temp->next; 
}
if(temp==NULL){
printf("\nData not found\n");
return; 
}
next=temp->next; 
if(prev==NULL)
head=next;
else
prev->next=next;
if(next!=NULL)
next->prev=prev;
free(temp); 
}
void display() {
if(head==NULL){
printf("\nList is Empty!!!\n");
return; 
}
printf("\nList elements: ");
Node* ptr=head; 
while(ptr!=NULL){
printf("%d ",ptr->data);
ptr=ptr->next; 
}
}
int main() {
int choice, value,key;
while(1){
printf("\n\n***** MENU *****\n");
printf("1. Insert Left\n2. Delete\n3. Display List\n4. Exit");
printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1: 
printf("Enter the value to be inserted: ");
scanf("%d", &value);
printf("Enter the key value: ");
scanf("%d", &key);
insert(value,key);
break;
case 2: 
printf("Enter the value to be deleted: ");
scanf("%d", &value);
delete(value); 
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

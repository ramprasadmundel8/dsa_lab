#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
char name[50];
struct node *next;
} Node;
Node *head = NULL;
void insert(char *name) {
Node *newNode = (Node*)malloc(sizeof(Node));
strcpy(newNode->name, name);
newNode->next = NULL;
if (head == NULL || strcmp(head->name, name) >= 0)
{
newNode->next = head;
head = newNode;
} else {
Node *current = head;
while (current->next != NULL && strcmp(current->next->name, name) < 0)
current = current->next;
newNode->next = current->next;
current->next = newNode;
}
}
void delete(char *name) {
Node *temp = head, *prev;
if (temp != NULL && strcmp(temp->name, name) == 0) {
head = temp->next;
free(temp);
return;
}
while (temp != NULL && strcmp(temp->name, name) != 0) {
prev = temp;
temp = temp->next;
}
if (temp == NULL)
return;
prev->next=temp->next; 
free(temp); 
}
void display() {
Node* ptr=head; 
printf("\nNames in the List: ");
while(ptr!=NULL){
printf("%s ",ptr->name);
ptr=ptr->next; 
}
}
int main() {
int choice; 
char value[50];
while(1){
printf("\n\n***** MENU *****\n");
printf("1. Insert Name\n2. Delete Name\n3. Display List\n4. Exit");
printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1: 
printf("Enter the Name to be inserted: ");
scanf("%s", value);
insert(value);
break;
case 2: 
printf("Enter the Name to be deleted: ");
scanf("%s", value);
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

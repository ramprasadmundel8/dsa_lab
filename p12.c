#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int data;
struct node *left;
struct node *right;
} Node;
Node *root = NULL;
Node* newNode(int data){
Node* temp=(Node*)malloc(sizeof(Node));
temp->data=data; 
temp->left=temp->right=NULL; 
return temp; 
}
Node* insert(Node* node,int data){
if(node==NULL)
return newNode(data); 
if(data<node->data)
node->left=insert(node->left,data);
else if(data>node->data)
node->right=insert(node->right,data);
return node; 
}
void inorder(Node* root){
if(root!=NULL){
inorder(root->left);
printf("%d ",root->data);
inorder(root->right); 
}
}
void preorder(Node* root){
if(root!=NULL){
printf("%d ",root->data);
preorder(root->left);
preorder(root->right); 
}
}
void postorder(Node* root){
if(root!=NULL){
postorder(root->left);
postorder(root->right); 
printf("%d ",root->data);
}
}
int main() {
int choice, value;
while(1){
printf("\n\n***** MENU *****\n");
printf("1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. 
Postorder Traversal\n5. Exit");
printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1: 
printf("Enter the value to be inserted: ");
scanf("%d", &value);
root=insert(root,value); 
break;
case 2: 
printf("\nInorder Traversal: ");
inorder(root); 
break;
case 3:
printf("\nPreorder Traversal: ");
preorder(root); 
break;
case 4:
printf("\nPostorder Traversal: ");
postorder(root); 
break;
case 5:
exit(0);
default:
printf("\nWrong selection!!! Please try again!!!\n");
}
}
}

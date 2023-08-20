#include<stdlib.h>
#include<stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push();
int pop();
void display();
void palin();
int main()
{ int c;
int a;
do{
printf("1-Push\n2-Pop\n3-Display\n4-Palindrome\n5-Exit :");
scanf("%d",&c);
switch(c){
case 1:
push();
break;
case 2:
a=pop();
if(a!=-1)
{
printf("The popped element is %d\n",a);
}
break;
case 3:
display();
break;
case 4:
palin();
break;
case 5:
break;
default:
printf("Wrong Choice\n");
}
}while(c!=5);
}
void push()
{
int v;
if(top==MAX-1)
{
printf("Stack Overflow");
}
else{
printf("Enter the element to be inserted :");
scanf("%d",&v);
stack[++top]=v;
}
}
int pop()
{
if(top==-1)
{
printf("Stack Underflow\n");
return -1;
}
else{
return stack[top--];
}
}
void display(){
printf("The stack elements are: \n");
for(int i=top;i>-1;i--)
{
printf("%d\t",stack[i]);
}printf("\n");
}
void palin(){
int floor=0;
int ceil=top;
int flag=0;
while(ceil>floor)
{
if(stack[ceil]==stack[floor])
{
flag=1;
}
else
{
flag=0;
}
ceil--;
floor++;
}
if(flag==1)
{
printf("The stack is palindrome\n");
}
else{
printf("The stack is not palindrome\n");
}
}

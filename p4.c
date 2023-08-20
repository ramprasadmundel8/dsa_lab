#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char a);
char pop();
int priority(char a);
void main(){
int c=0;
char a;
char infix[20];
printf("Enter the infix expression\n");
scanf("%s",infix);
printf("The Postfix Expression is:\n");
while(infix[c]!='\0'){
if(isalnum(infix[c]))
{
printf("%c",infix[c]);
}
else if(infix[c]=='(')
{
push(infix[c]);
}
else if(infix[c]==')')
{
while((a=pop())!='(')
{
printf("%c",a);
}
}
else{
while(priority(stack[top])>=priority(infix[c]))
{
printf("%c",pop());
}
push(infix[c]);
}
c++;
}
while(top!=-1)
printf("%c",pop());
printf("\n");
}
void push(char a)
{
if(top==MAX-1)
{
printf("Stack Overflow\n");
}
else{
stack[++top]=a;
}
}
char pop(){
if(top==-1)
{
return -1;
}
else{
return stack[top--];
}
}
int priority(char a){
int p=0;
switch(a){
case '(':
p=0;
break;
case '+':
case '-':
p=1;
break;
case '*':
case '/':
p=2;
break;
case '$':
case '^':
p=3;
break;
}
return p;
}

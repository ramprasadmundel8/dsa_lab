#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define MAX 100
int data[MAX];
int top;
void push(int item) {
if (top == MAX - 1) {
printf("Stack overflow\n");
return;
}
data[++top] = item;
}
int pop() {
if (top == -1) {
printf("Stack underflow\n");
return -1;
}
return data[top--];
}
int evaluate_postfix(char *exp) {
top = -1;
for (int i = 0; exp[i] != '\0'; i++) {
if (isdigit(exp[i])) {
push(exp[i] - '0');
} else {
int op2 = pop();
int op1 = pop();
int result;
switch (exp[i]) {
case '+':
result = op1 + op2;
break;
case '-':
result = op1 - op2;
break;
case '*':
result = op1 * op2;
break;
case '/':
result = op1 / op2;
break;
default:
printf("Invalid operator %c\n", exp[i]);
exit(1);
}
push(result);
}
}
return pop();
}
int main() {
char exp[100], *e;
printf("Enter the postfix expression: ");
scanf("%s", exp);
e=exp;
int result = evaluate_postfix(e);
printf("Result: %d\n", result);
return 0;
}

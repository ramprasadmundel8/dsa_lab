#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int ar[50];
int len;
void create();
void display();
void insert();
void delete();
void create()
{
printf("Enter the length :");
scanf("%d",&len);
printf("Enter array elements :");
for(int i=0;i<len;i++)
{
scanf("%d",&ar[i]);
}
}
void display(){
printf("The array elements:\n");
for(int i=0;i<len;i++)
{
printf("%d\t",ar[i]);
}
printf("\n");
}
void insert()
{
int pos;
int val;
printf("enter the pos in which the element has to be inserted\n");
scanf("%d",&pos);
if(pos<=len)
{
printf("enter the value :");
scanf("%d",&val);
for(int i=len;i>pos-1;i--)
{
ar[i]=ar[i-1];
}
ar[pos-1]=val;
len++;
}
else{
printf("Position not found\n");
}
}
void delete(){
int pos;
printf("enter the pos in which the element has to be deleted\n");
scanf("%d",&pos);
if(pos<=len)
{
for(int i=pos-1;i<len;i++)
{
ar[i]=ar[i+1];
}
len--;
}
}
int main()
{
int c=0;
do
{
printf("Enter choice\n1-Create\n2-Display\n3-Insert\n4-Delete\n5-Exit ");
scanf("%d",&c);
switch(c)
{
case 1:
create();
break;
case 2:
display();
break;
case 3:
insert();
break;
case 4:
delete();
break;
default:
printf("Wrong choice\n");
}
}while(c!=5);
return 0;
}

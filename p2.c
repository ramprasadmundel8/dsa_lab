#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct employee{
char name[20];
int id;
char dep_name[20];
float sal;
};
void depsal(struct employee* emp,int n);
void main(){
struct employee *ptr;
int n;
printf("Enter the number of employees: ");
scanf("%d",&n);
ptr=(struct employee*)malloc(n*sizeof(struct employee));
for(int i=0;i<n;i++)
{
printf("Enter employee %d name, id, dept name, salary: ",i+1);
scanf("%s%d%s%f",(ptr+i)->name,&(ptr+i)->id,(ptr+i)-
>dep_name,&(ptr+i)->sal); 
} 
printf("Employee Details\n");
printf("%15s%15s%15s%15s\n","EMP_NAME","EMP_ID","DEPT_NAME","SALARY");
for(int i=0;i<n;i++)
{
printf("%15s%15d%15s%15f\n",(ptr+i)->name,(ptr+i)->id,(ptr+i)-
>dep_name,(ptr+i)->sal);
}
depsal(ptr,n);
free(ptr);
}
void depsal(struct employee *emp,int n)
{
char depname[20];
float totalsal=0;
printf("Enter the department name: ");
scanf("%s",depname);
for(int i=0;i<n;i++){
if(strcmp(depname,(emp+i)->dep_name)==0)
{
totalsal=totalsal+(emp+i)->sal;
}
}
printf("Total Salary of %s is %.2f",depname,totalsal);
}

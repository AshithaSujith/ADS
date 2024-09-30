#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
void push(int x)
{
if(top==SIZE-1)
printf("\n Stack overflow occur,Insertion not possible.");
else
{
top=top+1;
stack[top]=x;
printf("\n insertion successfull");
}
}
void pop()
{
if(top==-1)
printf("\n stack underflow occur,deletion not possible");
else
{
int temp=stack[top];
top--;
printf("\n deleted element=%d",temp);
}
}
void display()
{
int i;
printf("\n the element in the stack are:");
for(i=top;i>=0;i--)
printf("%d",stack[i]);
}
void main()
{
int ch,value;
while(1)
{
printf("\n-----MENU------\n");
printf("\n1.insert \n2.delete \n3.display \n4.exit");
printf("\n enter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\n value to be inserted is:");
scanf("%d",&value);
push(value);
break;
case 2:pop();
break;
case 3:display();
break;
case 4:exit(0);
break;
default:printf("\n wrong choice!!");
}
}
}



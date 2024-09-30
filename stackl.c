#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}
*top=NULL;
void push()
{
struct node *newnode = (struct node *)malloc(sizeof(struct node));
printf("\n enter the data to be inserted:");
scanf("%d",&newnode->data);
if(top==NULL)
newnode->next=NULL;
else
newnode->next=top;
top=newnode;
}
void pop()
{
if(top==NULL)
printf("\n empty stack");
else
{
struct node * temp=top;
printf("\n deleted element::%d",temp->data);
top=temp->next;
free(temp);
}}
void display()
{
if(top==NULL)
printf("\n empty stack");
else
{
struct node * temp=top;
printf("\n stack is:");
while(temp!=NULL)
{
printf("%d--->",temp ->data);
temp=temp->next;
}
printf("NULL");
}}
void main()
{
int ch;
while(1)
{
printf("\n------\n \t\t MENU \n--------\n1.insert \n2.delete \n3.display \n4.exit \n");
printf("enter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:push();
break;
case 2:pop();
break;
case 3:display();
break;
case 4:exit(0);
break;
default:printf("wrong choice");
}
}
}

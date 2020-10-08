#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MALLOC(p,s,t)\
p=(t)malloc(s);\
if(p==NULL)\
{\
printf("Insufficient Memory\n");\
exit(1);\
}

int s[20],top,r=0;

struct car
{
char name[50];
int count;
char price[20];
struct car *link;
};
typedef struct car *NODE;

NODE head;

struct cust
{
char name[20];
int ch;
};

struct cust q[20];



NODE ins(NODE first,char name1[50],char price1[20],int count1)
{
NODE q,t;
t=first;
MALLOC(q,sizeof(struct car),NODE);
strcpy(q->name,name1);
strcpy(q->price,price1);
q->link=NULL;
q->count=count1;
if(!first)
first=q;
else
{
while(t->link)
t=t->link;
t->link=q;
};
return first;
}


void inill()
{
head=ins(head,"Lexus LFA","2.68 crores",1);
head=ins(head,"Aventador","4.76 crores",3);
head=ins(head,"Huracan","2.91 crores",4);
head=ins(head,"Taycan Turbo","1.32 crores",2);
head=ins(head,"911 Turbo","1.37 crores",2);
head=ins(head,"812 Superfast","5.20 crores",1);
head=ins(head,"AMG GT","2.32 crores",3);
head=ins(head,"BMW M5","1.54 crores",2);
head=ins(head,"BMW M4","1.35 crores",2);
head=ins(head,"BMW M3 GTR","1.56 crores",1);
}


void displayl(int n)
{
int i;NODE t=head;
for(i=1;i<n;i++)
t=t->link;
printf("%s\n",t->name);
}



void disll()
{
NODE t;
int i=1;
t=head;
printf("Name\t\t\t\tPrice\t\t\t\tStock\n");
while(t)
{
printf("%d.%s\t\t\t%s\t\t\t%d\n",i,t->name,t->price,t->count);
t=t->link;
i++;
};
}


void dissold()
{
int i;
for(i=top;i>=0;i--)
displayl(s[i]);
}


void push(int ch)
{ 
s[++top]=ch;
}


void enque(int ch1)
{ 
r++;
printf("Enter Name:\n");
scanf("%s",q[r].name);
q[r].ch=ch1;
}


void disq()
{ 
if(r==0)
printf("Que is Empty\n");
else
{
int i;printf("Customer Name\t\t\tCar Selected\n");
for(i=1;i<=r;i++)
{
printf("%s\t\t\t\t",q[i].name);
displayl(q[i].ch);
};
}
}



void order()
{ int ch,i;NODE t;
while(1)
{
printf("-----CARS MENU-----\n");
disll();
printf("Enter your choice :\n");
scanf("%d",&ch);
t=head;
for(i=1;i<ch;i++)
t=t->link;
if(t->count!=0)
{
printf("Order Placed\n");
enque(ch);
push(ch);
(t->count)=((t->count)-1);
printf("Current Que Status:\n");
disq();
getch();
return;
}
else
{
printf("No Stock\n");
printf("Continue Shopping?\n1.Yes\n2.No\nEnter Your Choice:\n");
scanf("%d",&ch);
if(ch!=1)
return;
};
};
}


void recentlysold()
{
int i;
if (top==0)
printf("No Cars Sold\n");
else
{
printf("Recently Sold Cars:\n\n");
for(i=top;i>0;i--)
{
printf("%d.",top-i+1);
displayl(s[i]);
};
};
getch();
}




void main()
{
inill();
int chm=1;
while(1)
{
printf("-----MAIN MENU-----\n1.Place an Order\n2.Recently Sold Cars\n3.Display Current Que Status\n4.Exit\nEnter Your Choice:\n");
scanf("%d",&chm);
switch(chm)
{
case 1:order();break;
case 2:recentlysold();break;
case 3:printf("Current Que Status:\n");
       disq();break;
case 4:printf("Exiting...\nPress any key\n");
getch();
exit(0);break;
default:printf("Invalid Choice\n");
};
};
}
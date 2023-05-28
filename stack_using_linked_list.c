//code to push and pop into stack and print in the files
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
}*node;


node cur=NULL;


int random_arr[100];
FILE *fptr,*fptr1,*fptr5,*fptr3,*fptr4;


node getnode()
{
node newn=(node)malloc(sizeof(struct node));
newn->next=NULL;

return newn;

}
node push(FILE *fptr4,node head)
{char str[5]="push";
char t='-';
node newn;

newn=getnode();
if(head==NULL)
{int a;
    head=newn;
    fscanf(fptr4,"%d",&a);
fptr=fopen("file_stack.txt","w+");
 //opening the file to print the operations
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%c",t);
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
newn->data=a;
head->next=NULL;

fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%d",head->data);
fprintf(fptr,"%d",head->data);
fclose(fptr5);
fclose(fptr3);

fclose(fptr1);
return head;
}
int a;
fscanf(fptr4,"%d",&a);
fptr=fopen("file_stack.txt","w+");
 //opening the file to print the operations
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%c",t);
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
newn->data=a;

newn->next=head;
head=newn;

fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%d",head->data);
node cur=head;

 //printing the pushed elements
while(cur!=NULL)
{
    fprintf(fptr,"%d ",cur->data);
    cur=cur->next;
      //printing the elements present in the stack
}

fclose(fptr1);
fclose(fptr5);
fclose(fptr);
return head;
}
void pop(node head)
{
int a;
char str[4]="pop";
node cur=head;
node prev=NULL;

while(cur->next!=NULL)
{prev=cur;
printf("k");
    cur=cur->next;
}
a=cur->data;
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%d",a);  //printimg the poped elements
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%c",'-');

prev->next=NULL;
node temp=head;
fptr=fopen("file_stack.txt","w+");
while(temp!=NULL)
{
    fprintf(fptr,"%d ",temp->data);
    temp=temp->next;  //printing the elements in the stack
}
fclose(fptr5);
fclose(fptr3);
fclose(fptr);

}
void random(int a,int b,int n)  //generating the random numbers in given range
{int s,count=0;

fptr4=fopen("file_random.txt","w");

    for(int i=0;count<n;i++)
    {
        s=rand()%10;
        if(s>=a&&s<=b)
        {count++;
        printf("l");
           fprintf(fptr4,"%d ",s);

        }
    }
    fclose(fptr4);

}

main()
{int a,b,n,j;
node head=NULL;
fptr=fopen("file_stack.txt","w");
fptr1=fopen("file_push.txt","w");
fptr5=fopen("file_print.txt","w");
fptr3=fopen("file_pop.txt","w");
fptr4=fopen("file_pop.txt","w");
fclose(fptr);
fclose(fptr1);
fclose(fptr5);
fclose(fptr3);
fclose(fptr4);//to open an empty file

printf("enter the range");
scanf("%d",&a);
scanf("%d",&b);
printf("enter the number of elements");
scanf("%d",&n);
random(a,b,n);

fptr4=fopen("file_random.txt","r");
while(1)
{printf("enter 1:push 2:pop");
scanf("%d",&j);
if(j==1)
{
  head=push(fptr4,head);
}
else if(j==2)
{
    pop(head);
}

}

fclose(fptr4);
}

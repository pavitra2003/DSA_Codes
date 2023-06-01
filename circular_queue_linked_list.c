
//code to enqueue and dequeue into queue and print in the files
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
}*node;


node front=NULL;
node rear=NULL;

int random_arr[100];
FILE *fptr,*fptr1,*fptr5,*fptr3,*fptr4;


node getnode()
{
node newn=(node)malloc(sizeof(struct node));
newn->next=newn;

return newn;

}



void enqueue(FILE *fptr4)
{char str[10]="enqueue";
char t='-';
node newn;

newn=getnode();
if(front==NULL)
{int a;
    front=newn;
    fscanf(fptr4,"%d",&a);
fptr=fopen("file_stack.txt","w+");
 //opening the file to print the operations
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%c",t);
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
newn->data=a;


rear=newn;


fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%d",front->data);
fprintf(fptr,"%d",front->data);
fclose(fptr5);
fclose(fptr3);

fclose(fptr1);

}
else{
int a;
fscanf(fptr4,"%d",&a);
fptr=fopen("file_stack.txt","w+");
 //opening the file to print the operations
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%c",t);
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
node cur=front;

while(cur!=rear)
{
    cur=cur->next;

}

newn->data=a;

rear->next=newn;

rear=newn;
newn->next=front;

fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%d",rear->data);
cur=front;

 //printing the enqueued elements
while(cur!=rear)
{printf("k");
    fprintf(fptr,"%d ",cur->data);
    cur=cur->next;
      //printing the elements present in the queue
}
fprintf(fptr,"%d ",cur->data);

fclose(fptr1);
fclose(fptr5);
fclose(fptr);
}
}



void dequeue()
{
int a;
 if(front==NULL)
    {
        printf("Underflow\n");
        front=NULL;rear=NULL;
    }
a=front->data;
char str[10]="dequeue";
node cur=front;
cur=cur->next;
front->next=NULL;
front=cur;
rear->next=front;


fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%d",a);  //printimg the dequeued elements
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%c",'-');


node temp=front;
fptr=fopen("file_stack.txt","w+");
while(temp->next!=front)
{
    fprintf(fptr,"%d ",temp->data);
    temp=temp->next;  //printing the elements in the queue
}
fprintf(fptr,"%d ",temp->data);
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
node front=NULL;
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
{printf("enter 1:enqueue 2:dequeue");
scanf("%d",&j);
if(j==1)
{
  enqueue(fptr4);
}
else if(j==2)
{
    dequeue();
}
}
fclose(fptr4);
}


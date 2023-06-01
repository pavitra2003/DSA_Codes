

//code to enqueue and dequeue into queue and print in the files
#include<stdio.h>
#include<stdlib.h>
struct priorityq
{
int items[100],f,r;

};
typedef struct priorityq PQ;

//PQ pq1;


int SIZE=100;


int random_arr[100];
FILE *fptr,*fptr1,*fptr5,*fptr3,*fptr4;
void enqueue(FILE *fptr4,PQ *pq1)
{char str[10]="enqueue";
char t='-';
int i;
if(pq1->r==SIZE-1)
{
    printf("overflow");
}
i=pq1->r;
pq1->r++;

int a,elem;
fscanf(fptr4,"%d",&elem);
fptr=fopen("file_stack.txt","w+");
 //opening the file to print the operations
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%c",t);
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
while(pq1->items[i] >= elem && i >= 0) /* Find location for new elem */
{
pq1->items[i+1]=pq1->items[i];
i--;
}
pq1->items[i+1]=elem;

 //updating the pointer

fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%d",pq1->items[i+1]); //printing the pushed elements
for(int i=pq1->f;i<=pq1->r;i++)
{
    fprintf(fptr,"%d ",pq1->items[i]);  //printing the elements present in the stack
}
fclose(fptr1);

fclose(fptr5);
fclose(fptr);
}




void dequeue(PQ *pq1)
{
int a,elem;
if(pq1->f > pq1->r)
printf("underflow");

char str[10]="dequeue";
elem=pq1->items[pq1->f];
pq1->f=pq1->f+1;
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%d",elem);  //printimg the poped elements
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%c",'-');


fptr=fopen("file_stack.txt","w+");
for(int i=pq1->f;i<=pq1->r;i++)
{
    fprintf(fptr,"%d ",pq1->items[i]);   //printing the elements in the stack
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
PQ pq11, *pq1;
pq1=&pq11;
pq1->f = 0;
pq1->r=-1;
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
  enqueue(fptr4,pq1);
}
else if(j==2)
{
   dequeue(pq1);
}
}

fclose(fptr4);
}

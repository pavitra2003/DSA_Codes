
//code to push and pop into stack and print in the files
#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int size=100;
int arr[100];
int random_arr[100];
FILE *fptr,*fptr1,*fptr5,*fptr3,*fptr4;
void enqueue(FILE *fptr4)
{char str[4]="push";
char t='-';
  if(rear==size-1)
    {
        printf("Overflow\n");
    }
if(front=-1)
{
    front=0;
}
int a;
fscanf(fptr4,"%d",&a);
fptr=fopen("file_stack.txt","w+");
 //opening the file to print the operations
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%c",t);
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
rear++;
 //updating the pointer
arr[rear]=a;
fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%d",arr[rear]); //printing the pushed elements
for(int i=front;i<=rear;i++)
{
    fprintf(fptr,"%d ",arr[i]);  //printing the elements present in the stack
}
fclose(fptr1);

fclose(fptr5);
fclose(fptr);
}




void dequeue()
{
int a;
char str[4]="pop";
a=arr[front];
  if(front==-1 || front>rear)
    {
        printf("Underflow\n");
        front=-1;rear=-1;
    }
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%d",a);  //printimg the poped elements
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%c",'-');


front++;
fptr=fopen("file_stack.txt","w+");
for(int i=front;i<=rear;i++)
{
    fprintf(fptr,"%d ",arr[i]);   //printing the elements in the stack
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
  enqueue(fptr4);
}
else if(j==2)
{
   dequeue();
}

}

fclose(fptr4);
}

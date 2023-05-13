#include<stdio.h>
#include<stdlib.h>
int top=-1;
int arr[100];
int random_arr[100];
FILE *fptr,*fptr1,*fptr5,*fptr3,*fptr4;
void push(FILE *fptr4)
{char str[4]="push";
int a;
fscanf(fptr4,"%d",&a);
fptr=fopen("file_stack.txt","w+");

fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);

top=top+1;
arr[top]=a;
fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%d",arr[top]);
for(int i=0;i<=top;i++)
{
    fprintf(fptr,"%d ",arr[i]);
}
fclose(fptr1);

fclose(fptr5);
fclose(fptr);
}
int pop()
{
int a;
char str[4]="pop";
a=arr[top];
fptr3=fopen("file_pop.txt","a");
fprintf(fptr3,"%d",a);
fptr5=fopen("file_print.txt","a");
fprintf(fptr5,"%s\n",str);
fptr1=fopen("file_push.txt","a");
fprintf(fptr1,"%c",' ');


top=top-1;
fptr=fopen("file_stack.txt","w+");
for(int i=0;i<=top;i++)
{
    fprintf(fptr,"%d ",arr[i]);
}
fclose(fptr5);
fclose(fptr3);
fclose(fptr);

}
void random(int a,int b,int n)
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
void display()
{fptr4=fopen("file_random.txt","r");
int l;

fscanf(fptr4,"%d",&l);
    printf("%d",l);


fclose(fptr4);
}
main()
{int a,b,n,j;
printf("enter the range");
scanf("%d",&a);
scanf("%d",&b);
printf("enter the number of elements");
scanf("%d",&n);
random(a,b,n);
display();
fptr4=fopen("file_random.txt","r");
while(1)
{printf("enter 1:push 2:pop");
scanf("%d",&j);
if(j==1)
{
  push(fptr4);
}
else if(j==2)
{
    pop();
}

}

fclose(fptr4);
}

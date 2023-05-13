
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
FILE *fptr;



void rad(int n) //function for n random number generation
{
int a,b;
fptr=fopen("file90.txt","w");
for(int i=0;i<n;i++)
{a=rand();
b=a%100;

    fprintf(fptr,"%d ",b);
}
fclose(fptr);
}
int a[100000];
main()
{int temp;
time_t t1,t2,t;
int n;
while(1)
{printf("enter the number of numbers to be sorted:");   //entering how many numbers to be sorted
scanf("%d",&n);
rad(n);
    fptr=fopen("file90.txt","r");
    for(long int i=0;i<n;i++)
    {
        fscanf(fptr,"%d",&a[i]);
         }
    t1=time(NULL); //storing the value of clock in t1

    for(long int i=0;i<n;i++)  //sorting the array of n numbers
    {
        for(long int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    t2=time(NULL); //storing the value of clock in t2
    t=t2-t1;  //calculation of time required for calculation
    fclose(fptr);
    fptr=fopen("file90.txt","w");
    for(long int i=0;i<n;i++)
    {
        fprintf(fptr,"%d ",a[i]);
    }
    fprintf(fptr,"\nTIME TAKEN:\n%ld",t);
    printf("%d",t);
    fclose(fptr);
}}

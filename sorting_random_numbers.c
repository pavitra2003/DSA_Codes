
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
FILE *fptr;



void rad(void) //function for random number generation
{
int a,b;
fptr=fopen("file90.txt","w");
for(int i=0;i<100;i++)
{a=rand();
b=a%100;

    fprintf(fptr,"%d ",b);
}
fclose(fptr);
}
int a[100];

main()
{int temp;
time_t t1,t2,t;
rad();
    fptr=fopen("file90.txt","r");//opening the file
    for(long int i=0;i<100;i++)
    {
        fscanf(fptr,"%d",&a[i]); //reading 100 random numbers
         }
    t1=time(NULL);   //making the clock on

    for(long int i=0;i<100;i++)   //sorting the numbers
    {
        for(long int j=i+1;j<100;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    t2=time(NULL);//making the clock off
    t=t2-t1;//calculating the time required for execution
    fclose(fptr);
    fptr=fopen("file90.txt","w");
    for(long int i=0;i<100;i++)
    {
        fprintf(fptr,"%d ",a[i]);
    }
    fprintf(fptr,"\nTIME TAKEN:\n%ld",t);
    fclose(fptr);
}

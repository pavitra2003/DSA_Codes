
#include<stdlib.h>
#include<stdio.h>
int a,b;
main()
{FILE *fptr;
fptr=fopen("file90.txt","w");
for(int i=0;i<100000;i++)
{a=rand();
b=a;

    fprintf(fptr,"%d ",b);
}
fclose(fptr);
}

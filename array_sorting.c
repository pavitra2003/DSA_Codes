
#include<stdio.h>
#include<math.h>
FILE *fptr,*fptr2;
int a[100],i=0,temp;
main()
{
    fptr=fopen("file1.txt","r");//opening the file to read array
    fptr2=fopen("file2.txt","w");//opening the files
    while(!feof(fptr))
    {
        fscanf(fptr,"%d",&a[i]);   //reading the array from file
i++;}
int count=i;
    for(int l=0;l<i-1;l++)   //sorting tr read array
    {
        for(int k=l+1;k<i-1;k++)
        {
            if(a[k]<a[l])
            {
                temp=a[l];
                a[l]=a[k];
                a[k]=temp;
            }
        }
    }

i=0;

        while(i<=count)
    {

        fprintf(fptr2,"%d",a[i]);  //writing the sorted array into the file
i++;
    }

    fclose(fptr);
    fclose(fptr2);
}

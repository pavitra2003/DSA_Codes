
#include<stdio.h>
#include<math.h>
FILE *fptr,*fptr1;
int n;

typedef struct array
{
int data;
struct array *next;
}*node;

node getnode() //creating a newnode
{int a;
    node newn;
    newn=(node)malloc(sizeof(struct array));
    if(newn==NULL)
    {
        printf("error");
        exit(0);
    }
    fscanf(fptr,"%d",&a);
//printf("%d",a);
    newn->data=a;

    newn->next=NULL;
    return newn;

}
node insert(node head) //inserting node at first
{node newn=getnode();
    if(head==NULL)
    {
        head=newn;

    }

    newn->next=head;
    head=newn;
    return head;
}
node sort(node head)  //function to sort numbers in linked list
{
node cur,p;
int temp;
cur=head;
p=cur->next;
for(int j=0;j<=4;j++)
{
    p=cur->next;
    for(int i=0;i<=5;i++)
{
    if(cur->data>p->data)
    {
    temp=cur->data;
        cur->data=p->data;
        p->data=temp;

        p=p->next;
    }
    else
    {
   p=p->next;
    }

}
cur=cur->next;}
return head;
}
main()
{node head=NULL;
    fptr=fopen("file23.txt","r");
    fptr1=fopen("file24.txt","w");
fscanf(fptr,"%d",&n);
for(int i=1;i<=n;i++)
{
    head=insert(head);

}
head=sort(head);
node cur=head;

for(int i=1;i<=n;i++)
{
    printf(" %d",cur->data);
    fprintf(fptr1," %d",cur->data);
    cur=cur->next;
}


fclose(fptr);
}

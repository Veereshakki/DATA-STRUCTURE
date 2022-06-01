#include<stdio.h>
struct recharge
{
    int cost,number;
    char brand[20];
    char network[20];
};
struct hotel
{
    int cost,days;
    char name[20];
    char place[20];
};
struct transaction
{
    struct recharge m;
    struct hotel n;
};
void read(struct transaction st[20],int N);
void display(struct transaction st[20],int N);
void total(struct transaction st[20],int N);
void highest(struct transaction st[20],int N);
int main()
{
    int N;
    struct transaction st[20];
    printf("enter the number of transactions\n");
    scanf("%d",&N);
    read(st,N);
    display (st,N);
    total(st,N);
    highest(st,N);
}
void read(struct transaction st[20],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("Enter cost brand network and number \n");
        scanf("%d%s%s%d",&st[i].m.cost,st[i].m.brand,st[i].m.network,&st[i].m.number);
    }
    for(i=0;i<N;i++)
    {
        printf("Enter  cost  no.days  name of hotel  location\n ");
        scanf("%d%d%s%s",&st[i].n.cost,&st[i].n.days,st[i].n.name,st[i].n.place);
    }
}
void display(struct transaction st[20],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("cost brand network of recharge is\n");
        printf("%d\t%s\t%s%d\n",st[i].m.cost,st[i].m.brand,st[i].m.network,st[i].m.number);
    }
    for(i=0;i<N;i++)
    {
        printf("cost  no.days  name of hotel  location is\n ");
        printf("%d\t%d\t%s\t%s\n",st[i].n.cost,st[i].n.days,st[i].n.name,st[i].n.place);
    }
}
void total(struct transaction st[20],int N)
{
    int i,sum;
    sum=0;
    for(i=0;i<N;i++)
    {
        sum=sum+st[i].m.cost;
    }
    printf("\nThe total amount spent on recharge is %d \n",sum);
}
void highest(struct transaction st[20],int N)
{
    int i,j,k,a,b;
    j=k=0;
    a=st[0].m.cost;
    b=st[0].n.cost;
    for(i=1;i<N;i++)
    {
        if(a<st[i].m.cost)
        {
            a=st[i].m.cost;
            j=i;
        }
    }
     for(i=1;i<N;i++)
    {
        if(b<st[i].n.cost)
        {
            b=st[i].n.cost;
            k=i;
        }
    }
    if(a>b)
    {
        printf("highest amount spent on recharge is %d and its brand, network and number is %s and %s  and %d",a,st[j].m.brand,st[j].m.network,st[j].m.number);
    }
    else
    {
         printf("highest amount spent on hotel transaction is %d and its days,name of hotel and location is %d %s and %s",b,st[k].n.days,st[k].n.name,st[k].n.place);
    }
}

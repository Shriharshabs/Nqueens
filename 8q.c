#include<stdio.h>

#define MAX 50
int n = 8;
int main()
{

    printf("Printing %d queens\n\n",n);
    int x=1,m=0,a[MAX][MAX],y=0,t=0,i,j,count=0;
    int solnCount =0;
    //initialising the chess board
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }

    a[0][0]=1;
   // printarr(a);
    while(1)//x is the row
    {
        y=m;
        while(y<n)
        {

            if(compare(a,x,y))
            {
                a[x][y]=1;
                x++;
                break;
            }
            y++;

        }
        if(y==n)
        {
            x=x-1;
            if(x==-1)
                exit(0);
            for(i=0;i<n;i++)
            {
                if(a[x][i]==1)
                {
                    a[x][i]=0;
                    m=i+1;
                    break;
                }
            }
        }
        else
            m=0;
        if(x==n){
            solnCount++;
            printf("%d Queen solution %d : \n\n",n,solnCount);
            printarr(a);
            printf("\n");

            if(solnCount==10000){
                break;
            }
        }

    }

    return 0;
}

int compare(int a[MAX][MAX],int b,int c)
{
    int x,y,c1=0,c2=0;
    //printarr(a);
    //printf("\n");
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            if(a[x][y]==1)
            {
               // printarr(a);
                //printf("\n");

                c1++;
                if(isattack(b,c,x,y))
                {
                    return 0;
                }
                else
                {
                    c2++;
                }


            }
        }
    }
    if(c1==c2)
    {
        return 1;
    }
    else
        return 0;
}
int isattack(int x1,int y1,int x2,int y2)
{
    int t1,t2;
    if((x1==x2)||(y1==y2))
        return 1;
    t1=x1-x2;
    t2=y1-y2;
    t1=mod(t1);
    t2=mod(t2);
    if(t1==t2)
            return 1;
     return 0;

}
int mod(int x)
{
    if(x>=0)
        return x;
    else
        return -x;
}
int printarr(int a[MAX][MAX])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c",a[i][j]==1?'X':'.');
        }
        printf("\n");
    }
}

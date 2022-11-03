#include<stdio.h>
#include<stdlib.h>
#define VAL 999
int i,j,k,a,b,u,v,n,edgecount=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int i)
{
    while(parent[i])
    i=parent[i];
    return i;
}
int union1(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
    printf("Enter the no. of vertices:");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=VAL;
        }
    }
    printf("The edges of Minimum Cost Spanning Tree are\n");
    while(edgecount < n)
    {
        for(i=1,min=VAL;i<=n;i++)
        {
            for(j=1;j <= n;j++)
            {
                if(cost[i][j] < min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(union1(u,v))
        {
            printf("%d edge : (%d,%d) =%d\n",edgecount++,a,b,min);
            mincost +=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost = %d\n",mincost);
    return 0;
}


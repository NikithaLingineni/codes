#include<stdio.h>
int merge(int arr[],int lb,int mid,int ub)
{
	int i,j,k;
	int n1=lb+ub+1;
	int b[n1];
	i=lb;
	j=mid+1;
	k=lb;
	while(i<=mid && j<=ub)
	{
		if(arr[i]<=arr[j])
		{
			b[k]=arr[i];
			i++;
			k++;
		}
		else
		{
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	else
	{
        while(i<=mid)
		{
			b[k]=arr[i];
			i++;
			k++;
		}
	}
	for(k=lb;k<=ub;k++)
	{
		arr[k]=b[k];
	}
}
void mergesort(int arr[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mergesort(arr,lb,mid);
		mergesort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
void printarray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main()
{
	int i,n;
	printf("enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	printf("sorted array:\n");
	printarray(arr,n);
	return 0;
}

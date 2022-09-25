#include<stdio.h>
int partition(int arr[],int lb,int ub)
{
	int pivot,start,end,temp;
	pivot=arr[lb];
	start=lb;
	end=ub;
	while(start<end)
	{
		while(arr[start]<=pivot)
		{
			start++;
		}
		while(arr[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			temp=arr[start];
			arr[start]=arr[end];
			arr[end]=temp;
		}
	}
	temp=arr[lb];
	arr[lb]=arr[end];
	arr[end]=temp;
	return end;
}
void Quicksort(int arr[],int lb,int ub)
{
	int loc;
	if(lb<ub)
	{
		loc=partition(arr,lb,ub);
		Quicksort(arr,lb,loc-1);
		Quicksort(arr,loc+1,ub);
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
	Quicksort(arr,0,n-1);
	printf("sorted array:\n");
	printarray(arr,n);
	return 0;
}

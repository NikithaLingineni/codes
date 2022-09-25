#include<stdio.h>
void selectionsort(int arr[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
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
	selectionsort(arr, n);
	printf("sorted array:\n");
	printarray(arr,n);
	return 0;
}

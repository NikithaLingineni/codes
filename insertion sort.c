#include<stdio.h>
void insertionsort(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
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
	insertionsort(arr, n);
	printf("sorted array:\n");
	printarray(arr,n);
	return 0;
}

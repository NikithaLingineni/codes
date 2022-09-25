#include<stdio.h>
int binarysearch(int arr[],int n,int target)
{
	int mid,start=0,end=n-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(arr[mid]==target)
		return mid;
		else if(arr[mid]<target)
		start=mid+1;
		else
		end=mid-1;
	}
	return -1;
}
int main()
{
	int i,n,target,result;;
	printf("enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the target:");
	scanf("%d",&target);
	result=binarysearch(arr, n, target);
	if(result==-1)
	{
		printf("not present");
	}
	else
	{
		printf("present at %d",result);
	}
	return 0;
}

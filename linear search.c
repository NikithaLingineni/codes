#include<stdio.h>
int main()
{
	int i,n,target,found=0;
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
	for(i=0;i<n;i++)
	{
		if(arr[i]==target)
		{
			found=1;
			break;
		}
	}
	if(found=1)
	{
	    printf("found at index %d",i);
	}
	else
	{
		printf("target value not found");
	}
	return 0;
}

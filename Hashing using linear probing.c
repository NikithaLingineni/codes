#include<stdio.h>
#include<stdlib.h>
void insert(int*h,int x,int n,int key)
{
	int i;
	int index=key%n;
	if(h[index]==0)
	{
	    h[index]=key;
	    printf("probe of key %d = 1\n",key);
    }
	else
	{
		int b;
		for(i=1;i<x;i++)
		{
			b=(index+i);
			if(h[b]==0)
			{
				h[b]=key;
				printf("probe of key %d = %d\n",key,i+1);
				return;
			}
		}
		printf("Hash table overflow");
	}
}
void Delete(int*h,int x,int n,int key)
{
	int i;
	int index=key%n;
	if(h[index]==key)
	h[index]=0;
	else
	{
		int b;
		for(i=1;i<x;i++)
		{
			b=(index+i);
			if(h[b]==key)
			{
				h[b]=0;
				printf("key %d is deleted",key);
				return;
			}
		}
		printf("Element not found");
	}
}
void search(int*h,int x,int n,int key)
{
	int i;
	int index=key%n;
	if(h[index]==key)
	printf("key %d is in the hash table at index %d",key,index);
	else
	{
		int b;
		for(i=1;i<x;i++)
		{
			b=(index+i);
			if(h[b]==key)
			{
				printf("key %d is in the hash table at index %d",key,b);
				return;
			}
		}
		printf("Element not found");
	}
}
void display(int*h,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("%d\n",h[i]);
	}
}
void delete_table(int*h,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		h[i]=0;
	}
}
int main()
{
	int i,n,k,a,choice,x;
	printf("Enter length of hash table:");
	scanf("%d",&n);
	printf("Enter number of elements do you want to enter:");
	scanf("%d",&a);
	if (a<n)
		x=n;
	else
	   x=a;
	int h[x];
	for(i=0;i<x;i++)
	{
		h[i]=0;
	}
	while(1)
	{
		printf("\nThe operations in hash Table are:\n");
		printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Delete table\n6.Exit\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter key:");
			       scanf("%d",&k);
			       insert(h,x,n,k);
			       break;
			case 2:printf("Enter key:");
			       scanf("%d",&k);
			       Delete(h,x,n,k);
			       break;
			case 3:printf("Enter key:");
			       scanf("%d",&k);
			       search(h,x,n,k);
			       break;
			case 4:display(h,x);
			       break;
			case 5:delete_table(h,x);
			       break;
			case 6:exit(0);
			default:printf("wrong choice");
			        break;
		}
	}
	return 0;
}

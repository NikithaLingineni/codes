#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*temp,*current,*prevnode;
void insert(struct node*h[],int key,int n)
{
	int i=key%n;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	if(h[i]==NULL)
	{
		temp->next=NULL;
	    h[i]=temp;
	}
	else
	{
		temp->next=h[i];
	    h[i]=temp;
	}
}
void Delete(struct node*h[],int key,int n)
{
	int i=key%n;
	temp=h[i];
	current=temp;
	prevnode=NULL;
	while(current && current->data!=key)
	{
		prevnode=current;
		current=current->next;
	}
	if(current==NULL)
	{
		printf("%d element is not in hash table",key);
	}
	else if(current==temp)
	{
		h[i]=current->next;
	}
	else
	{
		prevnode->next=current->next;
	}
	printf("%d element is deleted",key);
	free(current);
}
void search(struct node*h[],int key,int n)
{
	int i=key%n;
	temp=h[i];
	while(temp)
	{
		if(temp->data==key)
		{
			printf("Element %d is present in hash table at %d index",key,i);
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("%d element is not in hash table",key);
	}
}
void display(struct node*h[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		temp=h[i];
		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void delete_table(struct node*h[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		temp=h[i];
		while(temp)
		{
			h[i]=temp->next;
			free(temp);
			temp=h[i];
		}
	}	
}
int main()
{
	int i,n,k,choice;
	printf("Enter length of hash table:");
	scanf("%d",&n);
	struct node*h[n];
	for(i=0;i<n;i++)
	{
		h[i]=NULL;
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
			       insert(h,k,n);
			       break;
			case 2:printf("Enter key:");
			       scanf("%d",&k);
			       Delete(h,k,n);
			       break;
			case 3:printf("Enter key:");
			       scanf("%d",&k);
			       search(h,k,n);
			       break;
			case 4:display(h,n);
			       break;
			case 5:delete_table(h,n);
			       break;
			case 6:exit(0);
			default:printf("wrong choice");
			        break;
		}
	}
	return 0;
}

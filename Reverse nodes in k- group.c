#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head,*temp,*prevnode,*currentnode,*nextnode;
struct node *reverse(struct node *head,int k)
{
	if(!head)
	return NULL;
	int count=0;
	struct node*prevnode=NULL,*currentnode,*nextnode=NULL;
	currentnode=head;
	  while(currentnode!=NULL && count<k)
	  {
		nextnode=currentnode->next;
		currentnode->next=prevnode;
		prevnode=currentnode;
		currentnode=nextnode;
		count++;
	  }
	  if(nextnode!=NULL)
	  {
	  	head->next=reverse(nextnode,k);
	  }
	  return prevnode;
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int k;
	struct node*newnode;
	int choice=1;
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->next=NULL;
		printf("Enter the data you want to be inserted:");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		printf("Do you want to continue (1 or 0)?");
		scanf("%d",&choice);
	}
	printf("Linked list:\n");
	display();
	printf("\nEnter k value:");
	scanf("%d",&k);
	printf("Reversed Linked list:\n");
	head=reverse(head,k);
	display();
	return 0;
}

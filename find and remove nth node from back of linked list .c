#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head,*prevnode=NULL,*temp,*currentnode;
struct node* remove_nthnode(struct node*head,int B)
{
	int count=0;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	if(B>count)
	{	
	    printf("Length of linked list is %d\n",count);
	    printf("%d node is not found",B);
	}
	else if(B==count)
	return head->next;
	else
	{
		int i,diff=count-B;
		currentnode=head;
		for(i=0;i<diff;i++)
		{
			prevnode=currentnode;
			currentnode=currentnode->next;
		}	
		prevnode->next=currentnode->next;
	}
	printf("\nnth node from end of linked list is %d",currentnode->data);
	free(currentnode);
}
void display()
{
	temp=head;
	printf("\nLinked list is :\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main()
{
	struct node*newnode;
	int choice=1,x,B;
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
	display();
	printf("\nEnter the element you want to remove:");
	scanf("%d",&B);
	remove_nthnode(head,B);
	display();
	return 0;
}

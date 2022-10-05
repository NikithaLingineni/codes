#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head,*temp,*fast,*slow;
int countnodes(struct node *head)
{
	int res=1;
	temp=head;
	while(temp->next!=head)
	{
		res++;
		temp=temp->next;
	}
	return res;
}
int detectloop(struct node *head) 
{
    slow=head;
    fast=head;
    while(fast!=NULL &&fast->next!=NULL)
    {
    	slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        return countnodes(slow);
    }
    return 0; 
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
	head->next->next->next->next=head;
	if(detectloop(head))
	   printf("\nloop found");
	else
	printf("\nnot found");
	printf("\n%d",countnodes(head));
	return 0;
}

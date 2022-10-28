#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head,*temp,*fast,*slow;
struct node* detectloop(struct node *head) 
{
    slow=head;
    fast=head;
    while(fast!=NULL &&fast->next!=NULL)
    {
    	slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        break;
    }
    slow=head;
    while(slow!=fast)
    {
    	slow=slow->next;
        fast=fast->next;
	}
    return slow; 
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
	head->next->next->next->next->next=head->next->next;
	struct node*res=detectloop(head);
	if(res==NULL)
	   printf("\nloop not found");
	else
	printf("\nloop found and starting node is %d ",res->data);
	return 0;
}

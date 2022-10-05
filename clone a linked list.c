#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head=NULL,*temp,*newnode,*newlist=NULL,*tail=NULL,*dup;
struct node*insert(struct node*head,int data)
{
	newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    return newnode;
}
struct node* copy(struct node*head)
{
	temp=head;
	while(temp!=NULL)
	{
		if(newlist==NULL)
		{
			newlist=(struct node*)malloc(sizeof(struct node));
			newlist->data=temp->data;
			newlist->next=NULL;
			tail=newlist;
		}
		else
		{
			tail->next=(struct node*)malloc(sizeof(struct node));
			tail=tail->next;
			tail->data=temp->data;
			tail->next=NULL;
		}
		temp=temp->next;
	}
	return newlist;
}
void display(struct node*head)
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
	int n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	head=insert(head,i);
	display(head);
	dup=copy(head);
	display(dup);
	return 0;
}

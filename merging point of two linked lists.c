#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
	struct node* next;
};
struct node*head1,*head2,*ptr1,*ptr2,*temp,*newnode;
struct node* insert(int value)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=NULL;
	return newnode;
}
struct node* intersectPoint(struct node* head1,struct node* head2)
{
	ptr1 = head1;
	ptr2 = head2;
	if (ptr1 == NULL || ptr2 == NULL)
		return NULL;
	while (ptr1 != ptr2) {

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
        if (ptr1 == ptr2)
			return ptr1;
        if (ptr1 == NULL)
			ptr1 = head2;
     	if (ptr2 == NULL)
			ptr2 = head1;
	}
	return ptr1;
}
void display(struct node* head)
{
	temp=head;
	if (temp == NULL)
		printf("NULL");
	printf("\nLinked list is :\n");
	while (temp!= NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main()
{
	head1 = insert(10);
	
    head2 = insert(3);
    head2->next = insert(6);
    head2->next->next = insert(9);
    head2->next->next->next=head1->next=insert(15);
    head2->next->next->next->next=head1->next->next=insert(30);
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
	/*
	Create two linked lists

	1st Linked list is 3->6->9->15->30
	2nd Linked list is 10->15->30

	15 30 are elements in the intersection list*/
	struct node* intersect_node = NULL;
	intersect_node = intersectPoint(head1, head2);
	printf("INTERSEPOINT LIST :");
	display(intersect_node);
	return 0;
}


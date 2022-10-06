#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
	struct node* next;
};
struct node*head1,*head2,*ptr1,*ptr2,*temp;
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
	while (temp->next != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("%d", temp->data);
}
int main()
{
	/*
	Create two linked lists

	1st Linked list is 3->6->9->15->30
	2nd Linked list is 10->15->30

	15 30 are elements in the intersection list
	*/
	struct node* newNode;
	head1 = (struct node*)malloc(sizeof(struct node));
	head1->data = 10;
	head2 = (struct node*)malloc(sizeof(struct node));
	head2->data = 3;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 6;
	head2->next = newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 9;
	head2->next->next = newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 30;
	head1->next->next = newNode;
	head1->next->next->next = NULL;
	struct node* intersect_node = NULL;
	intersect_node = intersectPoint(head1, head2);
	printf("INTERSEPOINT LIST :");
	display(intersect_node);
	return 0;
}

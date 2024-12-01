#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
//struct node *create_node(int x);
struct node *create_node(int  new_data)
{
struct node *new_node=(struct node*) malloc (sizeof(struct node));
new_node->data=new_data;
new_node->next= NULL;
return new_node;
} 
void print(struct node *head){
	struct node *curr=head;
	printf("the entered value is\n");
	while(curr!=NULL){
		printf(" %d ",curr->data);
		curr=curr->next;
	}
	printf("\n");
}
struct node* insert_front(struct node *head,int value){
    struct node *temp=create_node(value);
    temp->next=head;
    
    head=temp;
    return head;
}
int main(){
	struct node *head=create_node(2);
    head->next=create_node(3);
    head->next->next=create_node(4);
    head->next->next->next=create_node(5);
	print(head);
	
	head=insert_front(head,6);
	print(head);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int data;
	struct node* next;
	struct node* prev;
};

struct node *create_node(int new_data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->next=NULL;
   	temp->prev=NULL;
	return temp;
}
struct node*print(struct node*head){
	struct node*temp=head;
	if(head=NULL){
		return NULL;
	}
	else{
		while(temp!=NULL){
	printf(" %d",temp->data);
	temp=temp->next;
   }
   printf("\n");
}
}

struct node*insert_front(struct node*head,int data){
	struct node* new_node=create_node(data);
	if(head==NULL){
	   return NULL;
	}
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
    return head;
	
}

struct node*insert_end(struct node*head,int data){
	struct node* new_node=create_node(data);
		 struct node*temp=head;
	if(head==NULL){
	   return new_node;
	}
	 while(temp->next!=NULL){
         temp=temp->next;
	 }
	     temp->next=new_node;
	     new_node->prev=temp;
	     return head;
	
}

int main()
{
	struct node* head=create_node(2);
	head->next=create_node(3);
	head->next->next=create_node(4);
	head->next->next->next=create_node(5);
	head->next->next->next->next=create_node(6);
	head->next->next->next->next->next=create_node(7);
		printf("The entered list :");
	print(head);

	head=insert_front(head,1);
	printf("\nAfter at front insertion: ");
	print(head);
	
	head=insert_end(head,8);
	printf("\nAfter at end insertion: ");
	print(head);
	
	return 0;
}

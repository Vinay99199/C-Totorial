#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *creation_node(int data){
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}

struct node* print(struct node*head){
struct node*temp=head;
   while(temp!=NULL){
   	printf(" %d",temp->data);
   	temp=temp->next;
   }
   printf("\n");
}

struct node *delete_first(struct node*head){
	struct node*temp=head;
		if(head==NULL){
	      	printf("list is empty");
		     return NULL;}
		else{
		  while(head!=NULL){
              head=head->next;
              free(temp);
              return head;
		    }
        }
    }  
struct node *delete_last(struct node*head){
     struct node *temp;
      struct node*prev;
	if(head==NULL){
		printf("list is empty");
		return NULL;
	}
    else{
         temp=head;
         while(temp->next!=NULL){
           prev=temp;
           temp=temp->next;
          }
    	prev->next=NULL;
    	free(temp);
    	}
    	return head;
}
struct node *delete_All(struct node*head){
	struct node*temp=head;
	struct node*meso;
	if(head==NULL){
		printf("list is empty");
		return NULL;
	}
	else{
	while(temp->next!=NULL){
		meso=temp->next;
		free(temp);
		temp=meso;
	}
  }
}
struct node*delete_pos(struct node*head,int key){
    struct node*prev;
    struct node*temp=head;
    	if(head==NULL){
		printf("list is empty");
		return NULL;
	}
	else{
	    while(temp->next!=NULL){
	        if(temp->data==key){
	            prev=temp->next;
	            free(temp);
	            temp=prev;
	        }
	        temp=temp->next;
	        return head;
	    }
	}
}

int main(){
 struct node*head=creation_node(2);
 head->next=creation_node(3);
 head->next->next=creation_node(4);
 head->next->next->next=creation_node(5);
 head->next->next->next->next=creation_node(6);
 head->next->next->next->next->next=creation_node(7);
 head->next->next->next->next->next->next=creation_node(8);
 head->next->next->next->next->next->next->next=creation_node(9);
printf("the entered value :");
print(head);

printf("\nAfter delete first node:");
head=delete_first(head);
print(head);

printf("\nAfter delete last node:");
head=delete_last(head);
print(head);

printf("\n After Delete a specific node:");
head=delete_pos(head,6);
print(head);

printf("\nAfter All node:");
head=delete_All(head);
print(head);

return 0;
}

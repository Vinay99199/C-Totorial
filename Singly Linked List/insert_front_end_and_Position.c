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
struct node* insert_end(struct node *head,int value){
  struct node *temp=create_node(value);
    if(head==NULL)
     {
       return temp;  }
     struct node *curr=head;
     while(curr->next!=NULL)
     { 
       curr=curr->next; }
      curr->next=temp;
      return head;
}
struct node *insert_position(struct node *head,int data){
	int pos=3;
    struct node *new_node=create_node(data);
    if(pos==1)  	
	return insert_front(head,data);  
              
    struct node *temp=head;
    
    for(int i=1;i<3&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("position is out of bound :\n");
        free(temp);
        return head;
    }
  new_node->next=temp->next;
   temp->next=new_node;
    return head;
}
int main(){
	struct node *head=create_node(2);
    head->next=create_node(3);
    head->next->next=create_node(4);
    head->next->next->next=create_node(5);
    printf("The entered node :");
	print(head);
	
	head=insert_front(head,6);
	  printf("After front insert node :");
	print(head);
	
	head=insert_end(head,9);
	  printf("After end insert node :");
	print(head);
	
	head= insert_position(head,12);
	  printf("After insert the Given position node :");
	print(head);
	return 0;
}

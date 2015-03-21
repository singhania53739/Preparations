#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node NODE;


NODE* createList(){ 
        NODE* head,*temp,*count; 
        int n=0,i; 
        printf("\nEnter size of linked list: "); 
        scanf("%d",&n); 
        if(n>0){ 
                head=(NODE *)malloc(sizeof(NODE*)); 
                printf("\nEnter data: "); 
                scanf("%d",&head->data); 
                head->next=NULL; 
 
                for(i=1;i<n;i++){ 
                        count=head; 
                        while(count->next!=NULL) 
                                count=count->next; 
 
                        temp=(NODE*)malloc(sizeof(NODE*)); 
                        printf("\nEnter data: "); 
                        scanf("%d",&temp->data); 
                        temp->next=NULL; 
                        count->next=temp; 
                } 
        } 
        return head; 
}

void printList(NODE *head){
    if(head!=NULL){
                NODE* count=head;
                printf("\n");
                while(count!=NULL){
                        printf("%d ",count->data);
                        count=count->next;
                }
        }
        else{
                printf("\nNo Linked List");
        }

}

NODE* reverse(NODE* head){

	NODE* prev=NULL,*curr=head,*next;
	if(head->next!=NULL){
		while(curr!=NULL){
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
	return prev;
	}
	return head;
}

NODE* palindrome(NODE* head){
	NODE* fast=head,*slow=head,*prev=head,*p1,*p2;
	
	while(fast!=NULL && fast->next!=NULL){
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	if(fast==NULL){
		prev->next=reverse(slow);
		p1=head;
		p2=prev->next;
		while(p2!=NULL && (p1->data==p2->data)){
			p1=p1->next;
			p2=p2->next;
		}

	}
	else{
		slow->next=reverse(slow->next);
		p1=head;
		p2=slow->next;
		while(p2!=NULL && (p1->data==p2->data)){
			p1=p1->next;
			p2=p2->next;
		}	
	}

	if(p2==NULL)
		printf("\nList is a palindrome.");
	else
		printf("\nList is not a palindrome");
	return head;	
}

int main(){
NODE* head=createList();
printList(head);
head= reverse(head);
printList(head);
head=palindrome(head);
printList(head);
}

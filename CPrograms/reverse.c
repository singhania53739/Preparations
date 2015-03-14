#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
        {
                int data;
                struct node* next;
        };
        typedef struct node NODE;


void linkPrint(NODE*);
NODE* linkReverse(NODE*);
void main(){

	NODE *head,*temp,*count;

	int ch;
	int i,n=0;
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

while(ch<3){
	printf("\nEnter \n1.Print\n2.Reverse\n3.Exit\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: linkPrint(head);
			break;
		case 2: head=linkReverse(head);
			break;
	}
}
}

void linkPrint(NODE *head){
    if(head!=NULL){
		NODE* count=head;
                while(count!=NULL){
                        printf("%d ",count->data);
                        count=count->next;
                }
        }
	else{
		printf("\nNo Linked List");
	}

}

NODE* linkReverse(NODE* head){
	NODE *prev,*curr,*next;
	if(head->next!=NULL){
		prev=NULL;
		curr=head;
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










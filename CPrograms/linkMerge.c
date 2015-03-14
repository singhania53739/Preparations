#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

typedef struct node NODE;
NODE* createLink(){
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

void linkPrint(NODE *head){
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

NODE* merge(NODE* head1,NODE*head2){
	NODE *count1=head1,*count2=head2,*temp,*prev=head1;
	while(count2!=NULL){
		if(head1->data>count2->data){
		temp=count2->next;
		count2->next=head1;
		head1=count2;
		count2=temp;			
		prev=head1;
}
		while(count1!=NULL){
			if(count1->data>count2->data){
				prev->next=count2;
				prev=prev->next;
				count2=count2->next;
				prev->next=count1;
				break;
			}else{
				prev=count1;
				count1=count1->next;
			}
		}
		if(count1==NULL&&count2!=NULL){
			prev->next=count2;
			count2=count2->next;
			prev=prev->next;
			prev->next=count1;
		}
	}
return head1;
}

void main(){
	NODE *head1,*head2,*merHead;

	printf("\nSorted Linked List 1: ");
	head1=createLink();
	linkPrint(head1);
	head2=createLink();
	linkPrint(head2);
	head1=merge(head1,head2);
	linkPrint(head1);
}

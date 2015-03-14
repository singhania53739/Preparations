#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
};

typedef struct node NODE;

NODE* createNode(int val){
	printf("\nCreating a new Node\n");
	NODE* temp=(NODE*)malloc(sizeof(NODE*));
	temp->data=val;
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;
}

NODE* insert(NODE* root,int val){
	
	if(root==NULL)
		root=createNode(val);
	else if(root->data < val)
		root->rchild = insert(root->rchild,val);
	else if(root->data > val)
		root->lchild = insert(root->lchild,val);
	return root;
}

NODE* search(NODE* root,int val){

	if(root==NULL || root->data==val)
		return root;

	if(root->data < val)
		return search(root->rchild,val);

	return search(root->lchild,val);
}


void inorder(NODE* root){

	if(root!=NULL){
		inorder(root->lchild);
		printf("%d ",root->data);
		inorder(root->rchild);
	}
}

void preorder(NODE* root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

int main(){
	NODE* root=NULL;
	int ch=0,val;
	while(ch<6){
		printf("\nEnter \n1.Insert\n2.InOrder\n3.PreOrder\n6.Exit ");
		scanf(" %d",&ch);
		switch(ch){

			case 1: printf("\nEnter Value: ");
				scanf("%d",&val);
				if(root==NULL)
					root = insert(root,val);
				else
					insert(root,val);
				break;

			case 2:	inorder(root);
				break;
			case 3: preorder(root);
				break;
		}
	}
	return 0;
}

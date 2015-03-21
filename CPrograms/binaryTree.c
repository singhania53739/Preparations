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

<<<<<<< HEAD
void postorder(NODE* root){

	if(root!=NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ",root->data);
	}

}
=======
>>>>>>> 4b3772d3a2528d495cefdbdf9d6c536075487ae4
NODE* minValNode(NODE* node){
	NODE* curr=node;
	while(curr->lchild!=NULL)
		curr=curr->lchild;
	return curr;
}

NODE* deleteVal(NODE* root, int val){
	if(root==NULL)
		return root;
	if(root->data < val)
		root->rchild = deleteVal(root->rchild,val);
	else if(root->data >val)
		root->lchild = deleteVal(root->lchild,val);
	else{
		if(root->lchild==NULL){
			NODE* temp = root->rchild;
			free(root);
			return temp;
		}
		else if(root->rchild==NULL){
			NODE* temp = root->lchild;
			free(root);
			return temp;
		}
		
		NODE* temp = minValNode(root->rchild);
		root->data=temp->data;
<<<<<<< HEAD
		root->rchild=deleteVal(root->rchild,temp->data);
=======
		root->rchild=deleteVal(root->right,temp->data);
>>>>>>> 4b3772d3a2528d495cefdbdf9d6c536075487ae4
	}
	return root;
}

int main(){
	NODE* root=NULL;
	int ch=0,val;
	while(ch<6){
		printf("\nEnter \n1.Insert\n2.InOrder\n3.PreOrder\n4.Delete\n6.Exit ");
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
				
			case 4: printf("\nEnter Value: ");
				scanf("%d",&val);
				root = deleteVal(root, val);
				break;
		}
	}
	return 0;
}

#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node NODE;



NODE* createNode(int data){

	NODE* temp =(NODE*)malloc(sizeof(NODE*));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

NODE* insert(NODE* root,int val){
	if(root==NULL)
		root=createNode(val);
	else if(root->data<val)
		root->right=insert(root->right,val);
	else if(root->data>val)
		root->left=insert(root->left,val);
	return root;
}

void preorder(NODE* root){
	if(root!=NULL){
		printf(" %d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(NODE* root){
	if(root!=NULL){
		inorder(root->left);
		printf(" %d",root->data);
		inorder(root->right);
	}
}

NODE* minVal(NODE* node){
	while(node->left!=NULL)
		node=node->left;
	return node;
}

NODE* deleteVal(NODE* root,int val){
	if(root==NULL)
		return root;
	if(val<root->data)
		root->left=deleteVal(root->left,val);
	else if(val>root->data)
		root->right=deleteVal(root->right,val);
	else{
		if(root->left==NULL && root->right!=NULL){
			NODE* temp = root->right;
			free(temp);
			return temp;
		}
		if(root->right==NULL&& root->left!=NULL){
			NODE* temp =root->left;
			free(temp);
			return temp;
		}
		NODE* temp = (NODE*)malloc(sizeof(NODE*));
		temp=minVal(root->right);
		root->data=temp->data;
		root=deleteVal(root->right,temp->data);
	}
	return root;
}

void printLeaf(NODE* root){
	if(root!=NULL){
		printLeaf(root->left);
		if(root->left==NULL && root->right==NULL)
			printf(" %d",root->data);
		printLeaf(root->right);
	}
}

int main(){
	NODE* root=NULL;
	int ch=0,val;
	while(ch<6){
		printf("\nEnter \n1.Insert\n2.InOrder\n3.PreOrder\n4.Delete\n5.Print Leaves\n6.Exit ");
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
			case 5: printLeaf(root);
				break;
		}
	}
	return 0;
}

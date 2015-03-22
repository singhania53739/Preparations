#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node NODE;

NODE* createNode(int val){
	NODE* temp=(NODE*)malloc(sizeof(NODE*));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int curr=0,pos=0;

NODE* createTree(int pre[],int post[],int size){
	NODE* root=createNode(pre[pos]);
	int i;
	for(i=0;i<size;i++){
		if(pre[pos]==post[i])
			break;
	}
	pos++;
	if(i!=curr){
		root->left=createTree(pre,post,size);
		root->right=createTree(pre,post,size);
		curr++;
	}else{
		curr++;
	}
	return root;
}

void inorder(NODE* root){
	if(root!=NULL){
		inorder(root->left);
		printf(" %d",root->data);
		inorder(root->right);
	}
}

int main(){
	int n,i;
	printf("\nEnter no of elements: ");
	scanf("%d",&n);
	int pre[n];
	int post[n];
	for(i=0;i<n;i++){
		printf("\nEnter Preorder element: ");
		scanf("%d",&pre[i]);
	}
	for(i=0;i<n;i++){
		printf("\nEnter Postorder elemt: ");
		scanf("%d",&post[i]);
	}
	NODE* root=createTree(pre,post,n);
	inorder(root);
}

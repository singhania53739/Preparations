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
	int i;
	NODE* root=createNode(pre[pos]);

	for(i=0;i<size;i++)
		if(post[i]==pre[pos])
			break;

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

int height(NODE* root){
	if(root==NULL)
		return 0;

	int lheight=height(root->left);
	int rheight=height(root->right);

	if(lheight>rheight)
		return lheight+1;
	return rheight+1;
}

void levelPrint(NODE* root,int level,int flag){
	if(root==NULL)
		return;
	if(level==1)
		printf(" %d",root->data);
	else if(level>1){
		if(flag==1){
			levelPrint(root->left,level-1,flag);
			levelPrint(root->right,level-1,flag);
		}else if(flag==-1){
			levelPrint(root->right,level-1,flag);
			levelPrint(root->left,level-1,flag);
		}
	}
}

void levelOrder(NODE* root){
	int i,h=height(root),flag=1;
	for(i=1;i<=h;i++){
		levelPrint(root,i,flag);
		flag=-flag;
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
	printf("\nheight is: %d\n",height(root));
	levelOrder(root);
}

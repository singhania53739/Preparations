#include<iostream.h>
#include<conio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node NODE;

NODE* createNode(int val){
	NODE* temp=new NODE;
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int curr=0,pos=0;
NODE* createTree(int pre[],int post[],int size){
	NODE* root=createNode(pre[pos]);

	for(int i=0;i<size;i++)
		if(post[i]==pre[pos])
			break;

	pos++;
	if(i!=curr){
		root->left=createTree(pre,post,size);
		root->right=createTree(pre,post,size);
		curr++;
	}else
		curr++;

	return root;
}
void inorder(NODE* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<" "<<root->data;
		inorder(root->right);
	}
}

void mirror(NODE* root){
	if(root==NULL)
		return;
	NODE* temp=root->left;
	root->left=root->right;
	root->right=temp;

	mirror(root->left);
	mirror(root->right);
}

int main(){
	clrscr();
	int pre[9]={1,2,4,8,9,5,3,6,7};
	int post[9]={8,9,4,5,2,6,7,3,1};
	NODE* root=createTree(pre,post,9);
	inorder(root);
	mirror(root);
	cout<<"\n";
	inorder(root);
	getch();

	return 1;
}

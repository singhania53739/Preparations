#include<iostream>
#include<stack>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node NODE;

NODE* createNode(int val){
	NODE* node= new NODE;
	node->data=val;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int curr=0,pos=0;

NODE* createTree(int pre[],int post[],int size){
	NODE* root=createNode(pre[pos]);
	int i;
	for(i=0;i<size;i++)
		if(pre[pos]==post[i])
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
		cout<<" "<<root->data;
		inorder(root->right);
	}
}

void spiralPrint(NODE* root){
	if(root==NULL) 
		return;

	stack<NODE*>s1;
	stack<NODE*>s2;
	s1.push(root);

	while(!(s1.empty()) || !(s2.empty())){

		while(!(s1.empty())){
			NODE* temp=s1.top();
			s1.pop();
			cout<<" "<<temp->data;
			if(temp->right!=NULL)
				s2.push(temp->right);
			if(temp->left!=NULL)
				s2.push(temp->left);
		}

		while(!(s2.empty())){
			NODE* temp=s2.top();
			s2.pop();
			cout<<" "<<temp->data;
			if(temp->left!=NULL)
				s1.push(temp->left);
			if(temp->right!=NULL)
				s1.push(temp->right);
		}
	}
}


int main(){
	int pre[9]={1,2,4,8,9,5,3,6,7};
	int post[9]={8,9,4,5,2,6,7,3,1};
	NODE* root=NULL;
	root=createTree(pre,post,9);
	inorder(root);
	spiralPrint(root);
	return 1;
}

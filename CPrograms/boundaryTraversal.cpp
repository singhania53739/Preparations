#include<iostream>

using namespace std;

struct node{
	int data;
	struct node* right;
	struct node* left;
};

typedef struct node NODE;

NODE* newNode(int val){
	NODE* temp=new NODE;
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void printLeft(NODE* root){

	if(root==NULL)
		return;
	if(root->left!=NULL){
		cout<<" "<<root->data;
		printLeft(root->left);
	}else if(root->right!=NULL){
		cout<<" "<<root->data;
		printLeft(root->right);
	}
}

void printRight(NODE* root){
	if(root==NULL)
		return;
	if(root->right!=NULL){
		printRight(root->right);
		cout<<" "<<root->data;
	}else if(root->left!=NULL){
		printRight(root->left);
		cout<<" "<<root->data;
	}

}

void printLeaves(NODE* root){
	if(root==NULL)
		return;
	printLeaves(root->left);
	if((root->left==NULL) && (root->right==NULL))
		cout<<" "<<root->data;
	printLeaves(root->right);
}

void printBoundary(NODE* root){
	if(root!=NULL){
		cout<<root->data;

		printLeft(root->left);
		printLeaves(root);
		printRight(root->right);

	}
}


int main(){
	NODE* root=newNode(1);
	root->left=newNode(2);
	root->left->right=newNode(3);
	root->left->right->left=newNode(4);
	root->left->right->left->right=newNode(5);
	root->right=newNode(6);
	root->right->right=newNode(7);
	root->right->right->left=newNode(8);
	printBoundary(root);
	return 1;

}

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
temp->right=NULL:
return temp;
}

NODE* createTree(int pre[],int post[],int l,int h){

}

int main(){}

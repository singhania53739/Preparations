#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node* left;
struct node* right;
};

typedef struct node NODE;

NODE* createNode(int val){
NODE* temp=(NODE*)malloc(sizeof(NODE*));
temp->left=NULL;
temp->right=NULL;
return temp;
}

int curr=0,pos=0;
NODE* createTree(int pre[],int post[],int size){
NODE* root=pre[pos];
int i;
for(i=0;i<size;i++)
if(pre[pos]==post[i])
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

int height(NODE* root){
if(root==NULL)
return 0;

int rheight=height(root->right);
int lheight=height(root->left);

if(lheight>rheight)
  return lheight+1;
return rheight+1;
}

void levelOrderPrint(NODE* root,int level){
if(root==NULL)
return;

if(level==1)
  printf(" %d",root->data);
else if(level>1){
  levelOrderPrint(root->left,level-1);
  levelOrderPrint(root->right,level-1);
}
}

void levelOrder(NODE* root){
  int i,h=height(root);
  for(i=1;i<=h;i++)
    levelOrderPrint(root,i);
}

void main(){
  int pre[9]={1,2,4,8,9,5,3,6,7};
	int post[9]={8,9,4,5,2,6,7,3,1};
	NODE* root=createTree(pre,post,9);
	levelOrder(root);
	
}

#include<iostream>
#include<stdlib>
using namespace std;

struct Node{
	int data;
	struct Node* next;
} *rear,*front;

void enqueue(int a){
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = a;
	newNode->next=NULL;
	if(front=NULL&&rear==NULL){
		front=newNode;
		rear=newNode;
	}else{
		rear->next=newNode;
		rear=newNode;
	}	
}


int dequeue(){
	int data;
	if(front!=NULL){
		struct Node *p=front;
		front=front->next;
		data=p->data;
		free(p);
	}
	else{cout<<"\nQueue is empty.";}
	return data;
}


void display(){
	struct Node* p=front;
	while(p!=NULL)
		cout<<"\n"<<p->data;
}


int main(){
	enqueue(2);
	cout<<dequeu();
}

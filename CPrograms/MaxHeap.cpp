#include<iostream>
#include<vector>
using namespace std;
int a[7]={2,4,1,6,8,3,5};
int size;
void maxHeapify(int i){
	int largest=i;
	int left=(i*2)+1;
	int right=(i*2)+2;
	if(left<size && (a[left]>a[largest]))
		largest=left;
	if(right<size && (a[right]>a[largest]))
		largest=right;

	if(i!=largest){
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxHeapify(largest);
	}

}

void createMaxHeap(){
	for(int i=(size-2)/2;i>=0;i--)
		maxHeapify(i);
}

void minHeapify(int i){
	int least=i;
	int left=(i*2)+1;
	int right=(i*2)+2;
	if(left<size && (a[left]<a[least]))
		least=left;
	if(right<size && (a[right]<a[least]))
		least=right;

	if(least!=i){
		int temp=a[least];
		a[least]=a[i];
		a[i]=temp;
		minHeapify(least);
	}
}

void createMinHeap(){
	for(int i=(size-2)/2;i>=0;i--)
		minHeapify(i);
}

void heapSort(){

	int s=size;
	for(int i=(size-2)/2;i>=0;i--)
		maxHeapify(i);
	cout<<"\nMaxHeap";
	for(int i=0;i<size;i++)
		cout<<" "<<a[i];

	while(size>1){
		int temp=a[0];
		a[0]=a[size-1];
		a[size-1]=temp;
		size--;
		maxHeapify(0);
	}
	size=s;
}

int kthLargest(int k){
	int s=size;

	for(int i=(size-2)/2;i>=0;i--)
		maxHeapify(i);
	cout<<"\nMaxHeap";
	for(int i=0;i<size;i++)
		cout<<" "<<a[i];

	while(k>0 && size>1){
		int temp=a[0];
		a[0]=a[size-1];
		a[size-1]=temp;
		size--;
		k--;
		maxHeapify(0);
	}
	int val=a[size];
	size=s;
	return val;
}

int main(){
	size=sizeof(a)/sizeof(a[0]);

	for(int i=0;i<size;i++)
		cout<<" "<<a[i];

	/*	createMaxHeap();

		cout<<"\nMaxHeap";
		for(int i=0;i<size;i++)
		cout<<" "<<a[i];
	//	createMinHeap();*/
	heapSort();
	cout<<"\nHeap Sorted:";
	for(int i=0;i<size;i++)
		cout<<" "<<a[i];
		cout<<"\nEnter K: ";
int k;
		cin>>k;
	cout<<"\n"<<kthLargest(k);
}



#include<iostream>
#include<vector>
using namespace std;

int heapSize;

vector<int> heapify(vector<int> a,int i){
int largest=i;
if(i<heapSize && (a[i]<a[(i+1)*2]))
largest=a[(i+1)*2];
if(a[largest]<a[(a+1)*2+1])
largest=a[(a+1)*2+1];

if(a[i]!=a[largest]){
int temp=a[i];
a[i]=a[largest];
a[largest]=temp;
}
if(i!=largest)
heapify(a,largest);
}

int main(){
  
  int a[7]={12,1,10,20,13,11,4};
  heapSize=7;
  for(int i=heapSize/2;i>=0;i--)
  heapify(a,i);
  
}




























package Others;

public class Heap {
	int[] a={20,12,5,9,22,51,1};
	int heapSize;

	void maxHeapify(int a[],int i){
		int lar=i;
		int left=(2*i)+1;
		int right=(2*i)+2;
		if(left<heapSize && a[left]>a[lar])
			lar=left;
		if(right<heapSize && a[right]>a[lar])
			lar=right;
		if(lar!=i){
			int temp=a[i];
			a[i]=a[lar];
			a[lar]=temp;
			maxHeapify(a, lar);
		}
	}

	void minHeapify(int a[],int i){
		int lea=i;
		int left=(i*2)+1;
		int right=(i*2)+2;
		if(left<heapSize && a[left]<a[lea])
			lea=left;
		if(right<heapSize && a[right]<a[lea])
			lea=right;
		if(lea!=i){
			int temp=a[lea];
			a[lea]=a[i];
			a[i]=temp;
			minHeapify(a, lea);
		}
	}

	public void heapSort(){

		heapSize=a.length;
		for (int i = (heapSize-2)/2; i >=0; i--)
			minHeapify(a, i);
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i]+" ");

		System.out.println();
		while(heapSize>1){
			int temp=a[0];
			a[0]=a[heapSize-1];
			a[heapSize-1]=temp;
			heapSize--;
			minHeapify(a, 0);
		}
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i]+" ");
	}

	public int kthLargest(int k){
		heapSize=a.length;
		int l=k;
		for (int i = (heapSize-2)/2; i >=0; i--)
			minHeapify(a, i);

		for (int i = 0; i < a.length; i++)
			System.out.print(a[i]+" ");

		System.out.println();

		while(k>0 && heapSize>1){
			int temp=a[0];
			a[0]=a[heapSize-1];
			a[heapSize-1]=temp;
			heapSize--;
			k--;
			minHeapify(a, 0);
		}

		return a[a.length-l];
	}

	public void heapBuilder(){
		heapSize=a.length;
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i]+" ");

		System.out.println();

		for(int i=(heapSize-2)/2;i>=0;i--)
			maxHeapify(a, i);


		for (int i = 0; i < a.length; i++)
			System.out.print(a[i]+" ");

		System.out.println();

		for(int i=(heapSize-2)/2;i>=0;i--)
			minHeapify(a, i);

		for (int i = 0; i < a.length; i++)
			System.out.print(a[i]+" ");

	}
}


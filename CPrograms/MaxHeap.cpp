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

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

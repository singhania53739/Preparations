#include<iostream>

using namespace std;

void rearr(int a[],int n){

	for(int i=0;i<n;i++){
		if(a[i]>0){
		int val=i;
		int j=a[i];
		while(j!=i){
			int newj=a[j];
			a[j]=-val;
//			cout<<"\n"<<a[j]<<"\n";
			val=j;
			j=newj;
		}
		a[i]=-val;
	}}
	for(int i=0;i<n;i++){
		if(a[i]<0)
		a[i]=-1*a[i];
		cout<<" "<<a[i];
	}

}



int main(){
	int n=0;
	cout<<"\n enter size: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cout<<"\nEnter element:";
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	rearr(a,n);
}

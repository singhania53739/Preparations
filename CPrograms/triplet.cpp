#include<iostream>
using namespace std;

int main(){

	int n;
	cout<<"\nEnter the size of array: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cout<<"\nEnter the value: ";
		cin>>a[i];
	}

	int sum;
	cout<<"\nEnter sum: ";
	cin>>sum;

	for(int i=0;i<n;i++){
		int f=i+1,l=n-1;
		while(l>f){
			if(a[i]+a[f]+a[l]==sum){
				cout<<"\nTriplets are: "<<a[i]<<" "<<a[f]<<" "<<a[l];
				return 1;
			}
			else if((a[i]+a[f]+a[l]) > sum)
				l--;
			else
				f++;

		}

	}
}

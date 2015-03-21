#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"\nEnter no of elements:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cout<<"\nEnter element: ";
		cin>>a[i];
	}

	int first=0,last=n-1,mid;
	while(first!=last){
		mid=(first+last)/2;
		if(a[mid]<mid)
			first=mid+1;
		else if(a[mid]>mid)
			last=mid-1;
		else{cout<<"\nElement is: "<<a[mid]<<"\n";return 1;}
	}
}

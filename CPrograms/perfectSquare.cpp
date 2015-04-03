#include<iostream>

using namespace std;

int main(){
	int n;
	cout<<"Enter the num: ";
	cin>>n;
	int f=1,l=n,mid;
	while(l>f){
		mid=(l+f)/2;
		if((mid*mid)<n)
			f=mid+1;
		else if((mid*mid)>n)
			l=mid-1;
		else
			break;
	}

	int a = mid * mid;
	int b = (mid + 1) * (mid + 1);

	if (n - a < b - n) {
		cout<<"\n"<<a;
	} else if (n - a > b - n) {
		cout<<"\n"<<b;
	} else {
		cout<<"\n"<<n;
	}
}


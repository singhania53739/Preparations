#include<iostream>
using namespace std;
const int size=20;

void findMatrix(int a[size][size],int n,int k){
	int i=0,j=n-1;

	while(i<n&&j>=0&&(a[i][j]!=k)){
		if(a[i][j]>k) 
			j--;
		else if(a[i][j]<k)
			i++;
	}

	if(a[i][j]==k)
		cout<<"\nrow "<<i<<" col "<<j;
	else
		cout<<"\nElement not found";
}



int main(){
	int n,k;
	cout<<"\nEnter size of matrix: ";
	cin>>n;
	int a[size][size];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cout<<"\nEnter "<<i<<","<<j<<" :";
			cin>>a[i][j];
		}
	while(1){
		int ch;
		cout<<"\n1.search\n2.exit ";
		cin>>ch;
		switch(ch){
			case 1:	cout<<"\nEnter K: ";
				cin>>k;
				cout<<"\nElement to be searched: "<<k<<"\n";
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++)
						cout<<a[i][j]<<" ";
					cout<<"\n";}
				findMatrix(a,n,k);
				break;
			case 2:return 0;
		}
	}
}

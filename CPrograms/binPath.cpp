#include<iostrem>
using namespace std;
const int size =20;

void path(int a[size][size],int n){

}



int main(){
	int n;
	int a[size][size];
	cout<<"\nEnter size of array: ";
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cout<<"\n Enter element i:"<<i<<" j:"<<j;
			cin>>a[i][j];
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)

			cout<<a[i][j]<<" ";
	}
	cout<<"\n";
path(a,n);

}

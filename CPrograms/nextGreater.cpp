#include<iostream>
#include<stack>

using namespace std;

int main(){
	int n;
	stack<int> s1;
	cout<<"\nEnter the size of the array";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cout<<"\nEnter the value: ";
		cin>>a[i];
	}
	s1.push(a[0]);
	int next;

	for(int i=1;i<n;i++){
		next=a[i];
		while(!s1.empty()){
			int temp=s1.top();
			s1.pop();
			if(next>temp){
				cout<<"\n"<<temp<<"-->"<<next;
			}else if(temp>next){
				s1.push(temp);break;
			}	
		}
		s1.push(next);
	}

	while(!s1.empty()){
		int temp=s1.top();
		s1.pop();
		next=-1;
		cout<<"\n"<<temp<<"-->"<<next;
	}

}

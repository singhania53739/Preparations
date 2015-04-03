#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

void prefixString(vector<string> v1){
	string prefix=v1[0];
	for(int i=1;i<v1.size();i++){
		int j=0;
		while(j<v1[i].size() && j<prefix.size()){
			if(prefix[j]==v1[i][j])
				j++;
			else{
				break;
			}
		}
		if(j>0) {

			cout << "\n shivaa" << prefix << "\n";
			prefix = prefix.substr(0,j);
			cout << "\n shivaa" << prefix << "\n";
		} else {
			prefix = "";
		}

	}
cout<<"\nPrefix is: "<<prefix<<"\n Lengthof str: "<<prefix.length()<<"\nSize: "<<prefix.size();

}


int main(){
	vector<string> v1;
	int n;
	cout<<"\nEnter number of string: ";
	cin>>n;
	for(int i=0;i<n;i++){
		string temp;
		cout<<"\nEnter String: ";
		cin>>temp;
		v1.push_back(temp);
	}
cout<<"\nStrings are:";
for(int i=0;i<v1.size();i++)
cout<<"\n"<<v1[i];

prefixString(v1);
}

#include<iostream>
#include<cstring>
using namespace std;

void reverse1(char *begin, char *end);

int main(){

	char a[50];
	cout<<"Enter a string ";
	cin.getline(a,49);
	cout<<"Current String: "<<a;
	int len=strlen(a);
	int i=0,j=len-1;char temp;
	char* begin=a;
	char* end=(a+len-1);
	reverse1(begin,end);
	begin=a;
	end=a;
	while(*end){
		end++;
		if(*end=='\0' || *end == ' '){
			reverse1(begin,end-1);
			begin=end+1;
		}
	}

	cout<<" "<<a<<" ";
}

void reverse1(char *begin, char *end){
	char temp;
	while(begin<end){
		temp=*begin;
		*begin=*end;
		*end=temp;
		begin++;
		end--;
	}
}


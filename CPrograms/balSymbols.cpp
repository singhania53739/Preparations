#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

class stack1{
public: 
void push(char a){
v1.push_back(a);
//cout<<(v1.back());
}
void pop(){
//cout<<(v1.back());
 v1.pop_back();
}
void printStack()
{
for(vector<char>::iterator itr = v1.begin();itr!=v1.end();itr++)
cout<<*itr<<endl;
}
private:
vector<char> v1;
};

int main(){
stack1 st;
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();

string str;
cin>>str;
for(int i=0;i<str.length();i++)
if(str[i]=='{'){
st.push(str[i]);
}
else if(str[i]=='}')
{st.pop();
}
else
cout<<str[i];
st.printStack();
return 0;
}

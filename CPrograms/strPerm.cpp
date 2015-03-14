#include<iostream>
#include<string>

using namespace std;

class Perm{
public:
	char *str;
	int len;
	Perm(char *arr)
	{
		int i=0;
		str= new char[5];
		while(*(arr+i)!='\0')
		{
			*(str+i)=*(arr+i);
			i++;
		}
		len=i;
//		cout<<len;
	}
	void swap(int i,int j)
	{
		char temp=*(str+i);
		*(str+i)=*(str+j);
		*(str+j)=temp;
	}

	void perm(int i){
		if(i==len-1)
		{
			int a=0;
			while(*(str+a)!='\0'){
				cout<<*(str+a);
				a++;
			}
cout<<"\n";

		}else{
			int b=i;
			while(*(str+b)!='\0'){
				swap(i,b);
				perm(i+1);
				swap(i,b);
				b++;
			}
		}
	}
};

  int main(){
                char *arr=new char[5];
                cout<<"\nEnter a string: ";
                cin>>arr;
                Perm obj(arr);
                obj.perm(0);
        }


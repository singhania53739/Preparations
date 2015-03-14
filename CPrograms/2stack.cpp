#include<iostream>

using namespace std;

class stack
{
	private:
		int *arr;
		int top1;
		int top2;
		int size;
	public:
		stack(int n){
			size=n;
			arr=new int[n];
			top1=-1;
			top2=size;
		}
		void push1(int ch){
			if(top1<top2-1){
				top1++;
				arr[top1]=ch;
			}
		}

		void push2(int ch){
			if(top2>top1+1){
				top2--;
				arr[top2]=ch;
			}
		}

		int pop1(){
			if(top1>=0)
				return arr[top1--];
		}

		int pop2(){
			if(top2<size)
				return arr[top2++];
		}

};



int main(){
	stack ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is " << ts.pop1();
	ts.push2(40);
	cout << "\nPopped element from stack2 is " << ts.pop2();
	return 0;
}

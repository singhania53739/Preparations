#include<iostream>
#define n 8
using namespace std;

void printSol(int a[n][n])
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<" "<<a[i][j]<<" ";
	cout<<"\n";
	}

}

int isSafe(int x, int y, int a[n][n])
{
    if ( x >= 0 && x < n && y >= 0 && y < n && a[x][y] == -1)
        return 1;
    return 0;
}


int solvektutil(int move_x,int move_y,int movei,int a[n][n],int x[],int y[]){

	if(movei==(n*n))
		return true;

	int next_x,next_y;

	for(int k=0;k<n;k++){

		next_x=move_x+x[k];
		next_y=move_y+y[k];

		if(isSafe(next_x,next_y,a)){

			a[next_x][next_y]=movei;
			if(solvektutil(next_x,next_y,movei+1,a,x,y)==true)
				return true;
			else
				a[next_x][next_y]=-1;
		}

	}
	return false;
}


void solvekt(){
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=-1;

	 int x[8] = {2,1,-1,-2,-2,-1,1,2 };
	 int y[8] = {1,2,2,1,-1,-2,-2,-1 };
	a[0][0]=0;
	if(solvektutil(0,0,1,a,x,y)==false){
		cout<<"\nNo solution";
		return;
	}
	else
		printSol(a);
}

int main(){
	solvekt();
}

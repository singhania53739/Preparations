#include<iostream>
#define n 4
using namespace std;

int isSafe(int maze[n][n],int x,int y){
	if(x<n && x>=0 && y<n && y>=0 && maze[x][y]==1)
		return 1;
	return 0;
}

int printSol(int a[n][n]){
	cout<<"\n\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<" "<<a[i][j]<<" ";
		cout<<"\n";
	}
}
int solveMaze(int maze[n][n],int x,int y,int a[n][n]){
	if(x==n-1 && y==n-1)
		return 1;

	if(isSafe(maze,x,y)){
		a[x][y]=1;
		if(solveMaze(maze,x+1,y,a))
			return 1;
		if(solveMaze(maze,x,y+1,a))
			return 1;
		a[x][y]=0;
		return 0;
	}
	return 0;
}

void maze(int maze[n][n]){
	int a[n][n]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

	if(solveMaze(maze,0,0,a)==0)
	{
		cout<<"\nNo Solution.";
		return;
	}
	a[n-1][n-1]=1;
	printSol(a);
}


int main(){
	int a[n][n] = {{1,0,0,0},{1,1,0,0},{0,1,0,1},{1,1,1,1}};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<" "<<a[i][j]<<" ";
		cout<<"\n";
	}
	maze(a);
	return 1;
}

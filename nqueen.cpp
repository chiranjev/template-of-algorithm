#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

bool isSafe(int board[][100],int i,int j,int n)
{
	int x,y;
	// check for upper column
	for(int row=0;row<i;row++)
	{
		if(board[row][j]==1)
			return false;
	}
	x=i-1;
	y=j-1;
	// check for left upper diagonal
	while(x>=0&&y>=0)
	{
		if(board[x][y]==1)
			return false;
		x--;
		y--;
	}

	x=i-1;
	y=j+1;
	// check for right upper diagonal
	while(x>=0&&y<n)
	{
		if(board[x][y]==1)
			return false;
		x--;
		y++;
	}

	return true;

}

bool solveNQueen(int board[][100],int i,int n)
{
	//Base Case
	if(i==n)
	{
		// You have successfully placed queens in n rows (0...n-1)
		// Print n rows
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				if(board[i][j]==1)
					cout << "Q ";
				else
					cout << "_ ";
				cout << endl;
		}

		cout << endl << endl;

		return false; // set true if only one configuration is to be printed
						  // for all configurations to be printed set false
	}
	else  // Recursive Case
	{
		// Try to place the queen in current row and call on the remaining part
		// which will be solved by recursion
		for(int j=0;j<n;j++)
		{
			// First check if (i,j) position is safe or not to place the queen
			if(isSafe(board,i,j,n))
			{
				board[i][j]=1; // Place the queen at (i,j) position

				bool nextQueenPossible=solveNQueen(board,i+1,n);

				if(nextQueenPossible){
					return true;
				}
				// means i,j is not the right position - Assumption is wrong
				board[i][j]=0; // backtrack
			}
		}

		return false;  // You have tried for all positions in current row but couldn't place a queen
	}
}

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		 // for getting input from input.txt
		 freopen("input.txt", "r", stdin);
		 // for writing output to output.txt
		 freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,len,n,sum,count;
	string s;
	int t;

	cin >> n;
	int board[100][100];
	solveNQueen(board,0,n);


	return 0;
}

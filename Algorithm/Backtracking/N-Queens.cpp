#include<iostream>
#define n 4

using namespace std;

bool isSafe(int board[n][n], int row, int col)
{
	int i, j;
	//check same row, left
	for(i=0; i<col; i++)
	{
		if(board[row][i])
			return false;
	}
	//check upper diagonal
	for(i=row, j=col; i>=0 && j>=0; i--, j--)
	{
		if(board[i][j]) {
			return false;
		}
	}
	//check lower diagonal
	for(i=row, j=col; i<n && j>=0; i++, j--)
	{
		if(board[i][j]) {
			return false;
		}
	}
	return true;
}


bool nqueen(int board[n][n], int col)
{
	if(col>=n) {
		return true;
	}
	
	for(int i=0; i<n; i++)
	{
		if(isSafe(board, i, col)) {
			board[i][col] = 1;
			if(nqueen(board, col+1)) {
				return true;
			}
			board[i][col] = 0;
		}
	}
	return false;
}

void print(int board[n][n])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<board[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	int board[4][4] ={ {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
	};
	if(nqueen(board, 0)) {
		print(board);
	}
	else {
		cout<<"Solution doesnot exist"<<endl;
	}
	return 0;
}

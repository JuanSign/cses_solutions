//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

#define Checker vector<bool>

//solve recursively
void solve(string board[8], int row, int& ans,
		   Checker& columns,
		   Checker& diag1,
		   Checker& diag2)
{	
	//base case (reach the end)
	if(row == 8)
	{
		ans++;	
		return;
	}
	
	//trying to place a queen on every column in row (row)
	for(int col = 0; col < 8; col++)
	{
		//check conditions
		if(columns[col] || 
		   diag1[row-col+7] || 
		   diag2[row+col] ||
		   board[row][col] == '*') continue;
	
		//place a queen here, and update conditions
		columns[col] = diag1[row-col+7] = diag2[row+col] = true;
		//place a queen in the next row
		solve(board, row+1, ans, columns, diag1, diag2);
		//take the queen back, update conditions
		columns[col] = diag1[row-col+7] = diag2[row+col] = false;	
	}
}

int main()
{
	fastio()
		
	//input chessboard
	string board[8];
	for(int i = 0; i < 8; i++) cin >> board[i];
	
	//checkers
	//columns[i] = true if theres exist a queen in column ii
	Checker columns(8, false);	
	//if theres a queen in some (row,col) diag1[row-col+7] = true
	Checker diag1(15, false); 
	//if theres a queen in some (row,col) diag2[row+col] = true
	Checker diag2(15, false);
	
	int ans = 0;
	//solve
	solve(board, 0, ans, columns, diag1, diag2);
	cout << ans << nn;
}

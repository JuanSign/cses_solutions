//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
		
	//input a and b
	int a, b; cin >> a >> b;
	
	//dp[i][j] := number of cuts required to turn a ixj rectangle into a square
	int dp[a+1][b+1];
	
	//iterate from the smallest i, j
	for(int i = 1; i <= a; i++)
	{
		for(int j = 1; j <= b; j++)
		{
			if(i==j) dp[i][j] = 0; //already a square
			else
			{	
				//declare as infinite
				dp[i][j] = INT_MAX;
				//we make a cut at column k
				for(int k = 1; k < j; k++)
				{	
					//now we have 2 rectangles
					//(ixk) and (ix(j-k))
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
				}	
				//we make a cut at row k
				for(int k = 1; k < i; k++)
				{
					//now we have 2 rectangles
					//(kxj) and ((i-k)xj)
					dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
				}
			}
		}
	}
	
	cout << dp[a][b] << nn;
}

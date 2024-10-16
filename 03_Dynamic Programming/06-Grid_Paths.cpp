//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
		
	//mod
	int mod = 1e9+7;
	
	//input data
	int n; cin >> n;
	string map[n];
	for(int i = 0; i < n; i++) cin >> map[i];
	
	//dp[i][j] := number of ways to reach grid[i][j]
	//initially all zero
	vector<vector<int>> dp(n, vector<int>(n,0));
	
	//straight connected line to the righ of [0][0] 
	for(int i = 0; i < n; i++)
	{
		//disconnected
		if(map[0][i] == '*') break;
		dp[0][i] = 1;
	}
	
	//straight connected line to the buttom of [0][0]
	for(int i = 0; i < n; i++)
	{
		//disconnected
		if(map[i][0] == '*') break;
		dp[i][0] = 1;
	}
	
	//check map
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(map[i][j] == '*') continue;
			//coming from left
			dp[i][j] += dp[i][j-1];
			dp[i][j] %= mod;
			//coming from above
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= mod;
		}
	}
	
	//output
	cout << dp[n-1][n-1] << nn;
}

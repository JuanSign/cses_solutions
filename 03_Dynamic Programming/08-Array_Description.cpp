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
	int n, m; cin >> n >> m;
	int data[n];
	for(int i = 0; i < n; i++) cin >> data[i];	
	
	//dp[i][j] := number of ways to place j as the ith index
	vector<vector<int>> dp(n, vector<int>(m+2,0)); //initially all zero
		
	//check first element
	if(data[0])
	{
		//first element is determined
		dp[0][data[0]] = 1;
	}
	else
	{
		//first element is 0
		for(int i = 1; i <= m; i++) dp[0][i] = 1;
	}
	
	//check second until last element
	for(int i = 1; i < n; i++)
	{
		//if the ith element is determined
		if(data[i])
		{
			//add the number of ways to choose the (i-1)th element
			//the (i-1)th element can be data[i]-1, data[i], or data[i]+1
			dp[i][data[i]] += dp[i-1][data[i]-1];
			dp[i][data[i]] %= mod;
			dp[i][data[i]] += dp[i-1][data[i]];
			dp[i][data[i]] %= mod;
			dp[i][data[i]] += dp[i-1][data[i]+1];
			dp[i][data[i]] %= mod;
		}
		else
		{
			//the ith element has m options, and for each options, we add the corresponding (i-1)th element
			for(int j = 1; j <= m; j++)
			{	
				dp[i][j] += dp[i-1][j-1];
				dp[i][j] %= mod;
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= mod;
				dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= mod;
			}
		}
	}
	
	//answer
	int ans = 0;
	
	//add all ways to choose the last element
	for(int i = 1; i <= m; i++)
	{
		ans += dp[n-1][i];
		ans %= mod;
	}
	
	//output
	cout << ans << nn;
}

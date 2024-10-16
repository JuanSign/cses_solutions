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
	int n, x; cin >> n >> x;
	int coins[n];
	for(int i = 0; i < n; i++) cin >> coins[i];
	
	//dp[i] := number of distinct ways to produce sum i
	int dp[x+1] = {0}; //initially all zero
	//1 way to produce sum 0
	dp[0] = 1;

	//iterate from 1 to x
	for(int i = 1; i <= x; i++)
	{
		//choose coins[c] as the last coin
		for(int c = 0; c < n; c++)
		{
			if(i - coins[c] < 0) continue;
			dp[i] += dp[i-coins[c]];
			dp[i] %= mod;
		}
	}		
	
	cout << dp[x] << nn;
}

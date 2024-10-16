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
	
	//dp[i] := number of distinct ordered coins to produce sum i
	int dp[x+1] = {0}; //initially all zero
	//1 way to produce sum 0
	dp[0] = 1;
	
	//choose a coin
	for(int c = 0; c < n; c++)
	{
		//update dp	
		for(int i = coins[c]; i <= x; i++)
		{
			dp[i] += dp[i-coins[c]];
			dp[i] %= mod;
		}
	}
	
	cout << dp[x] << nn;
}

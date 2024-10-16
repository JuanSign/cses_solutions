//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input data
	int n, x; cin >> n >> x;
	int coins[n];
	for(int i = 0; i < n; i++) cin >> coins[i];

	//dp[i] := minimum number of coins to produce sum i
	int dp[x+1];
	//0 coin to produce sum 0
	dp[0] = 0;
	
	//iterate from 1 to x
	for(int i = 1; i <= x; i++)
	{
		//initialize dp[i] as "infinite"
		dp[i] = 1e6+1;
		for(int c = 0; c < n; c++)
		{
			//minimum number of coins if we choose coins[c] as the last coin
			//	1 + minimum number of coins to produce sum i-coins[c]
			//if possible
			if(i - coins[c] < 0) continue;
			//get minimum among all c
			dp[i] = min(dp[i], 1+dp[i-coins[c]]);
		}
	}	
	
	//output
	if(dp[x] != 1e6+1) cout << dp[x] << nn;
	else cout << -1 << nn;
}

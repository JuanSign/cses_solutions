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
	int weight[n];
	for(int i = 0; i < n; i++) cin >> weight[i];
	
	//dp[i] := {rides taken, available slot on new rides} in the subset-i 
	pair<int,int> dp[1<<n];
	dp[0] = {1,0};
	
	//iterate every subset
	for(int i = 1; i < (1<<n); i++)
	{
		//declare as infinite
		dp[i] = {INT_MAX, INT_MAX};
	
		//check every mask
		for(int mask = 0; mask < n; mask++)
		{
			//if the i-th bit is on
			if(i&(1<<mask))
			{
				//update value
				if(dp[i^(1<<mask)].second + weight[mask] <= x)
				{
					dp[i] = min(dp[i], {dp[i^(1<<mask)].first, dp[i^(1<<mask)].second+weight[mask]});
				}
				else
				{
					dp[i] = min(dp[i], {dp[i^(1<<mask)].first+1, weight[mask]});
				}
			}
		}
	}
	cout << dp[(1<<n)-1].first << nn;	
}

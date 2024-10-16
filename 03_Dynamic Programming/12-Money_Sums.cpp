//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
		
	//input data
	int n; cin >> n;
	int maks = 0;
	int coins[n];
	for(int i = 0; i < n; i++)
	{
		cin >> coins[i];
		maks += coins[i];
	}
	
	//dp[i][j] := whether we can create sum j using the first i coin
	bool dp[n+1][maks+1];
	dp[0][0] = true;
	for(int i = 1; i <= maks; i++) dp[0][i] = false;
	
	vector<int> ans;

	//try to use the first i coins
	for(int i = 1; i <= n; i++)
	{
		//try to create sum j
		for(int j = 0; j <= maks; j++)
		{
			//if we can create j using the first (i-1) coins
			//then we can make j using the first i coins
			dp[i][j] = dp[i-1][j];
	
			//if j is larger than or equal to coins[i-1]
			//we check if we can create j-coins[i-1] using the first (i-1) coins
			if(j >= coins[i-1] && dp[i-1][j-coins[i-1]]) dp[i][j] = true;
		
			if(i == n && j && dp[i][j]) ans.push_back(j);
		}
	}
	
	cout << ans.size() << nn;
	for(int i : ans) cout << i << " ";
}

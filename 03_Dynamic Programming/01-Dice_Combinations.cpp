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
	
	//input n
	int n; cin >> n;
	
	//dp[i] := ways to construct sum n by throwing a dice one or more times
	int dp[n+1] = {0}; //initially all zero
	//1 way to construct sum = 0
	dp[0] = 1;
	
	//iterate from 1 to n
	for(int i = 1; i <= n; i++)
	{
		//the last dice we throw [1,6]
		for(int dice = 1; dice <= 6; dice++)
		{
			//ways to construct sum = i is equal to
			//throwing (dice) as your last dice
			//and ways to construct sum = i-dice
			//as long as i-dice >= 0
			if(i-dice < 0) break;
			dp[i] += dp[i-dice];
			dp[i] %= mod;
		}
	}
	
	//output
	cout << dp[n] << nn;
}

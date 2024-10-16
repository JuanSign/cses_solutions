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

	//precompute
	//dp[i][0] := number of towers with height i and no vertical line at the topmost level
	//dp[i][1] := number of towers with height i and theres a vertical line at the topmost level
	
	long long dp[(int)1e6+1][2];
	dp[1][0] = 1;
	dp[1][1] = 1;
	
	//compute for height = 2 to 1e6
	for(int i = 2; i <= (int)1e6; i++)
	{
		//initialize as 0
		dp[i][0] = 0;
		dp[i][1] = 0;
	
		//we can have a vertical line at the topmost level
		//in 4*(number of towers of height i-1 with vertical line at its topmost level) ways
		//and in (number of towers of height i-1 with no vertical line at its topmost level) ways
		dp[i][1] += 4*(dp[i-1][1]);
		dp[i][1] %= mod;
		dp[i][1] += dp[i-1][0];
		dp[i][1] %= mod;
	
		//we can have no vertical at the topmost level
		//in 2*(number of towers of height i-1 with no vertical line at its topmost level) ways
		//and in (number of towers of height i-1 with a vertical line at its topmost level) ways
		dp[i][0] += 2*dp[i-1][0];
		dp[i][0] %= mod;
		dp[i][0] += dp[i-1][1];
		dp[i][0] %= mod;
	}
	
	//input t
	int t; cin >> t;
		
	while(t--)
	{
		//input n
		int n; cin >> n;
		//output total number of towers;
		cout << ((dp[n][0] + dp[n][1])%mod) << nn;
	}
}

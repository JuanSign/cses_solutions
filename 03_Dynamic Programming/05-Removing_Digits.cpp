//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n
	int n; cin >> n;
	
	//dp[i] := number of steps to turn i into 0 using the given operation
	int dp[n+1];
	dp[0] = 0;
	for(int i = 1; i <= min(9,n); i++) dp[i] = 1;
	
	//iterate from 10 to n
	for(int i = 10; i <= n; i++)
	{
		//define dp[i] as infinite
		dp[i] = INT_MAX;

		//turn i into string
		string s = to_string(i);

		//check every digits and get the minimum
		for(char c : s)
		{
			if(c == '0') continue;
			dp[i] = min(dp[i], 1+dp[i-(c-'0')]);
		}
	}
		
	cout << dp[n] << nn;
}

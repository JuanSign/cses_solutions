//JuanSign
#include <bits/stdc++.h>
using namespace std;

//god helped me on this one

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
 
long long dp[19];
 
long long solve(long long n)
{
	if(n == 0) return 1;
	if(n < 0) return 0;
	string num = to_string(n);
	long long sum = 0;
	for(int i = 0; i < (int)num.length(); i++) sum += dp[i];
	int prev = 0;
	for(int i = 0; i < (int)num.length(); i++)
	{
		int cur = num[i]-'0';
		int mul = cur - (cur > prev);
		sum += (mul*dp[num.length()-i-1]);
		if(cur == prev) return sum;	
		prev = cur;
	}
	return sum+1;
}
 
int main()
{
	fastio()
	dp[0] = 1;
	for(int i = 1; i < 19; i++) dp[i] = dp[i-1]*9;
	long long a, b; cin >> a >> b;
	cout << (solve(b)-solve(a-1)) << nn;
}


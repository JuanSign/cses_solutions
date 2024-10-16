//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//this one is too complex to be explained by comments only :(

int mod = 1e9+7;
int n, m;
int dp[1001][1<<10];
 
void fill(int col, int id, int currMask, int nextMask)
{
	if(id == n)
	{
		dp[col+1][nextMask] += dp[col][currMask];
		dp[col+1][nextMask] %= mod;
		return;
	}
	if(currMask & (1<<id)) fill(col, id+1, currMask, nextMask);
	else
	{
		fill(col, id+1, currMask, nextMask | (1<<id));
		if(id+1<n && (!(currMask & ((1<<(id+1)))))) fill(col, id+2, currMask, nextMask);
	}
}
 
int main()
{
	fastio()
	cin >> n >> m;
	dp[0][0] = 1;
	for(int col = 0; col < m; col++)
		for(int bitmask = 0; bitmask < (1 << n); bitmask++)
			if(dp[col][bitmask]) fill(col,0,bitmask,0);	
	cout << dp[m][0] << '\n';
} 

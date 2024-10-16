//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input string a and b
	string a, b;
	cin >> a >> b;
	
	//count length of a and b
	int na = a.length();
	int nb = b.length();
	
	//dp[i][j] := cost of turning the first i elements of a into the first j elements of b
	int dp[na+1][nb+1];
	
	//turning the first 0 element (empty string) of a into the first i elements of b cost i operations
	for(int i = 0; i <= nb; i++) dp[0][i] = i;
	//turning the first 0 element (empty string) of b into the first i elements of a cost i operations
	for(int i = 0; i <= na; i++) dp[i][0] = i;
	
	//we check for every i and j
	for(int i = 1; i <= na; i++)
	{
		for(int j = 1; j <= nb; j++)
		{
			//if the ith element of a is equal the jth element of b
			//then the cost is the same as turning the first (i-1) elements of a into the first (j-1) elements of b
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else
			{
				//declare as infinite
				dp[i][j] = INT_MAX;
				//we can choose to erase the ith element of a 
				//and turn the first (i-1) elements of a into the first j elements of b
				dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
				//we can choose to insert the jth element of b into the end of a
				//and turn the first i elements of a into the first (j-1) elements of b
				dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]);
				//we can choose to replace the ith element of a into the jth element of b
				//and turn the first (i-1) elements of a into the first (j-1) elements of b
				dp[i][j] = min(dp[i][j], 1 + dp[i-1][j-1]);
			}
		}
	}
	
	//output the cost to turn the first (na) elements of a into the first (nb) elements of b
	cout << dp[na][nb] << nn;
}

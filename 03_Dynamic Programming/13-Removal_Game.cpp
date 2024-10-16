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
	int data[n];
	for(int i = 0; i < n; i++) cin >> data[i];	
	
	//dp[i][j] := given range i to j (inclusive) 
	//			  dp[i][j] is the sum of number taken by first player (respectively) 
	//			  minus the sum of number taken by second player (respectively)
	long long dp[n][n];
	for(int i = 0; i < n; i++) dp[i][i] = data[i];
	
	//for any given range [i,j]
	//we can count the score by
	//if we take the leftmost number
	//	data[i] - dp[i+1][j] (minus because respectively we are the second player)
	//if we take the rightmost number
	//  data[j] - dp[i][j-1] (minus because respectively we are the second player)
	
	//we have two pointer, right and left
	//left will start at index n-2
	//right will start from left+1 ... n-1
	for(int left = n-2; left >= 0; left--)
	{
		for(int right = left+1; right < n; right++)
		{
			//if we take leftmost
			long long tL = data[left] - dp[left+1][right];
			//if we take rightmost
			long long tR = data[right] - dp[left][right-1];
			//we want the maximum out of the 2 options
			dp[left][right] = max(tR,tL);
		}
	}
	
	//sum - dp[0][n-1] will resulting in 2*(sum of number taken by first player)
	cout << ((accumulate(data,data+n,(long long)0)+dp[0][n-1])/2) << nn;
}

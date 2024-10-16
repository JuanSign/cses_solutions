//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
		
	//mod and mod inverse of 2
	int mod = 1e9+7;
	int twoInv = 5e8+4;
	
	//input n
	int n; cin >> n;
	
	//calculate the sum of 1...n
	long long sum = (n*(n+1))/2;
	
	//if sum cant be divided into 2 equal sets...
	if(sum%2)
	{
		cout << 0 << nn;
		return 0;
	}
	
	//divide the sum by 2 to get the target sum for each subset
	sum /= 2;
	
	//dp[i] := number of subset with sum equal i
	long long dp[sum+1] = {0}; //initially all zero
	
	//considering only 0
	dp[0] = 1;
	//current maximum sum that we can reach
	long long maxVal = 0;
	 
	//trying to consider every element from 1 to n sequentially
	for(int i = 1; i <= n; i++)
	{
		//new maximum that we can reach
		maxVal += i;	
		//trying to fill dp[maxVal]...dp[i]
		//we dont need to calculate dp[maxVal] when maxVal > sum
		for(int curSum = min(maxVal,sum); curSum >= i; curSum--)	
		{
			//since we're considering element i
			//we know that the number of subset with sum = (curSum)
			//can be added by the number of subset with sum = (curSum-i)
			//	since we're inserting i into that subset
			dp[curSum] += dp[curSum-i];
			dp[curSum] %= mod;
		}
	}
		
	//modular arithmetic :)
	cout << dp[sum]*twoInv%mod << nn;
}

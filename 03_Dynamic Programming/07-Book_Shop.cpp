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
	int price[n], pages[n];
	for(int i = 0; i < n; i++) cin >> price[i];
	for(int i = 0; i < n; i++) cin >> pages[i];
	
	//dp[i] := maximum pages we can buy with budget i	
	int dp[x+1] = {0}; //initially all zero
	
	//consider using book 0...i
	for(int i = 0; i < n; i++)
	{
		//check for every budget
		for(int budget = x; budget > 0; budget--)
		{	
			//check if we can by book i with current budget
			if(price[i] > budget) break;	
			//buy book i and update dp
			dp[budget] = max(dp[budget], dp[budget-price[i]]+pages[i]);
		}
	}
	
	cout << dp[x] << nn;
}

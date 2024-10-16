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
	
	//dp[i] := smallest element in the end of a (i+1) elements increasing subseq
	//		   if dp[i] = INT_MAX, theres no subseq of length (i+1)
	vector<int> dp(n, INT_MAX); //initially all INT_MAX

	//process every element sequentially
	for(int i = 0; i < n; i++)
	{
		//find the first element that is >= data[i]
		auto it = lower_bound(dp.begin(), dp.end(), data[i]);
		//replace that element with data[i]
		*it = data[i];
	}
	
	//output the biggest i that is not INT_MAX
	for(int i = n-1; i >= 0; i--)
	{
		if(dp[i] != INT_MAX) 
		{
			cout << i+1 << nn;
			return 0;
		}
	}
}

//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

bool check(long long data[], int n, int k, long long mid)
{
	int count = 1;
	long long curSum = 0;
	for(int i = 0; i < n; i++)
	{
		curSum += data[i];
		if(curSum > mid)
		{
			count++;	
			curSum = data[i];
		}
		if(count > k) return false;
	}
	return true;
}

int main()
{
	fastio()
	
	//input data
	int n, k; cin >> n >> k;
	long long data[n];
	for(int i = 0; i < n; i++) cin >> data[i];
	
	//get minimum and maximum possible sum of subarray
	long long minimum = *(max_element(data, data+n));
	long long maximum = accumulate(data, data+n, (long long)0);
	
	//declare answer
	long long ans;
	
	//binary search to find solution between [minimum, maximum];
	while(minimum <= maximum)
	{
		long long mid = (minimum+maximum)/2;
		if(check(data, n, k, mid))
		{
			ans = mid;
			maximum = mid-1;
		}
		else minimum = mid+1;
	}
	
	cout << ans << nn;
}

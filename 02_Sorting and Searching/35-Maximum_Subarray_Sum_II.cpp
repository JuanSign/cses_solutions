//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input data
	int n, a, b;
	cin >> n >> a >> b;
	//prefix sum
	vector<long long> pref(n+1);
	pref[0] = 0;
	for(int i = 1; i <= n; i++) //1-indexing
	{
		cin >> pref[i];
		pref[i] += pref[i-1];
	}
	
	//maintain a multiset to store the prefix sum of all considered subarray
	multiset<long long> sums;
	//subarray sum of a subarray that starts in a and ends in b is
	//pref[b]-pref[a-1]
	//so if were in pref[i], the maximum subarray with a <= length <= b is
	//max(pref[i+a]...pref[i+b]) - pref[i]
	
	//load the first [a,b] to compared with pref[0]
	for(int i = a; i <= b; i++) sums.insert(pref[i]);
	
	long long ans = *sums.rbegin() - pref[0];
		
	//iterate i from 1 to n-a
	for(int i = 1; i <= n-a; i++)	
	{	
		//remove leftmost element
		sums.erase(sums.find(pref[i+a-1]));
		//add new element (if available)
		if(i+b <= n) sums.insert(pref[i+b]);
		//calculate new maximum subarray sum
		ans = max(ans, (*sums.rbegin()-pref[i]));
	}
	
	cout << ans << nn;
}


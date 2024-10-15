//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//same approach as (28_Subarray_Sums_II.cpp)
	int n; cin >> n;
	int data[n]; 
	for(int i = 0; i < n; i++) cin >> data[i];
	
	map<long long, long long> count;
	count[0] = 1;
	
	long long ans = 0;
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = ((sum+data[i])%n + n)%n;
		ans += count[sum];
		count[sum]++;
	}
	
	cout << ans << nn;
}

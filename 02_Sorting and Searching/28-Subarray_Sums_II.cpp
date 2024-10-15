//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()

	//input data
	long long n, x; cin >> n >> x;
	long long data[n];
	for(int i = 0; i < n; i++) cin >> data[i];
	
	//unordered_map to count apperance of prefix sum
	map<long long, long long> count;
	count[0] = 1;
	
	long long ans = 0;
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		//update current prefix-sum
		sum += data[i];
		//count the apperance of prefix-sum with sum sum-x;
		ans += (count.find(sum-x) == count.end())? 0 : count[sum-x];
		//update count
		if(count.find(sum) != count.end()) count[sum]++;
		else count.insert({sum, 1});
	}
	
	cout << ans << nn;
}

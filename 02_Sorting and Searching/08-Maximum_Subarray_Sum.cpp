//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input array
	int n; cin >> n;
	int data[n]; 
	for(int i = 0; i < n; i++) cin >> data[i];
	
	//declaring variable
	long long ans = LONG_LONG_MIN;
	long long cur = 0;
	
	for(int i = 0; i < n; i++)
	{
		//adding data[i] to current sum
		cur += data[i];
		//updating total best
		ans = max(ans,cur);
		//if current sum is negative, reset to 0
		cur = max(cur, (long long)0);
	}
	
	cout << ans << nn;
}

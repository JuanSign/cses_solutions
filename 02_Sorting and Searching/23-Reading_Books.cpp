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
		
	//keep track of maximum reading time, and sum of total reading time
	long long maks = LONG_LONG_MIN;
	long long sum  = 0;
	long long cur;
	
	for(int i = 0; i < n; i++)
	{
		cin >> cur;
		maks = max(maks, cur);
		sum += cur;
	}
	
	//if the maximum is >= the rest,
	//	Kotivalo can read the maximum, and Justiina read everything else
	//	then Justiina can read the maximum while Kotivalo read everything else
	//if the maximum is < the rest,
	// Kotivalo can read the maximum, while Justiina starts reading from the minimum
	// after Kotivalo finished, Kotivalo can starts reading and will finished after Justiina
	// finished reading the maximum. Total = Justiina Time = SUM
	cout << max(sum, 2*maks) << nn;
}

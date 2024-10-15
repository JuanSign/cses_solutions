//JuanSign
#include <bits/stdc++.h>
using namespace std;
 
#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//solve 
int solve(int n, int x, int data[])
{
	//current subarray sum
	int sum = 0;
	
	//index to insert
	int insert = 0;
	//index to remove
	int remove = 0;
	
	//count
	int count = 0;
	
	while(insert < n)
	{
		while(insert < n && sum < x) sum += data[insert++];
		while(remove < insert && sum > x) sum -= data[remove++];
		if(sum == x)
		{
			count++;
			sum -= data[remove++];
		}
	}

	return count;
}
 
int main()
{
	fastio()
	
	//input data
	int n, x; cin >> n >> x;
	int data[n];
	for(int i = 0; i < n; i++) cin >> data[i];
	
	//solve and output
	cout << solve(n, x, data) << nn;
}

//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//solve recursively
long long solve(int data[], long long sumA, long long sumB, int i, int n)
{
	//base case
	if(i == n)
	{
		return abs(sumA-sumB);
	}
	
	//case if data[i] go to sumA
	long long A = solve(data, sumA+data[i], sumB, i+1, n);
	//case if data[i] go to sumB
	long long B = solve(data, sumA, sumB+data[i], i+1, n);
	
	//return the minimum
	return min(A,B);
}

int main()
{
	fastio()
		
	//input n
	int n; cin >> n;
	//input array
	int data[n]; 
	for(int i = 0; i < n; i++) cin >> data[i];
	
	cout << solve(data, 0, 0, 0, n) << nn;
}

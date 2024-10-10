//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//solve recursively
int solve(int n)
{
	//every multiple of 5 will contribute a 5
	//every multiple of 25 will contribute 2 5's
	
	if(n == 0) return 0;
	return n/5 + solve(n/5);

	//iteratively...
	//	int n = ...;
	//	int divisor = 5;
	//	int ans = 0;
	//	while(n > 0)
	//		ans += n/divisor
	//		divisor *= 5
}

int main()
{
	fastio()
	
	//if the number X has prime factorization of 2^X x 5^Y x ...
	//then the number of trailing zeros is Y
	//since every 5 will be paired with a 2
	//note that X will always be larger than Y
	//because 2 appears in every even number and 5 only appears in the multiple of 5
	
	//input n
	int n; cin >> n;
	cout << solve(n) << nn;
}

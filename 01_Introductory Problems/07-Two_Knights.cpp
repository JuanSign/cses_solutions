//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//solve for any given k
unsigned long long solve(int k)
{
	unsigned long long K = k;
	//total configurations
	unsigned long long total = (K*K)*(K*K-1)/2;
	
	//every 2x3 grid and 3x2 grid gives 2 invalid configurations
	//every kxk squares have (k-1)(k-2) 2x3 grid
	//	(k-1) ways to place vertically, (k-2) ways to place horizontally
	//every kxk squares have (k-2)(k-1) 3x2 grid
	//	(k-2) ways to place vertically, (k-1) ways to place horizontally
	//therefore, total invalid configurations is 4(k-1)(k-2)
	
	unsigned long long invalid = 4*(K-1)*(K-2);
	
	return (total-invalid);
}

int main()
{
	fastio()
	
	//input n
	int n; cin >> n;
	
	//solve for every k = 1 to k = n
	for(int k = 1; k <= n; k++)
	{
		cout << solve(k) << nn;
	}
}

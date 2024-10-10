//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	//bit string of length n
	//every bit has 2 possibilities (either 0 or 1)
	//therefore the answer is 2^n
	
	//input n
	int n; cin >> n;
	
	//count 2^n mod 1e9+7
	int mod = 1e9+7;
	int ans = 1;
	while(n--) ans = (ans*2)%mod;
	cout << ans << nn;
}

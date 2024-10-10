//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n
	long long n; cin >> n;
	
	//do operations
	while(n != 1)
	{
		cout << n << " ";
		n = (n%2)? (n*3+1) : (n/2);	
	}
	
	//output 1
	cout << 1 << nn;
}

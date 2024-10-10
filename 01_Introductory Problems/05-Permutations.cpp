//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n
	int n; cin >> n;
	
	//no valid solution for n smaller than 4
	//except n = 1
	if(n == 1) cout << 1;
	else if(n < 4)
	{
		cout << "NO SOLUTION" << nn;
	}
	else
	{
		//greedy approach
		//print even numbers increasingly
		//print odd numbers increasingly
		for(int i = 2; i <= n; i += 2) cout << i << " ";
		for(int i = 1; i <= n; i += 2) cout << i << " ";
	}
}

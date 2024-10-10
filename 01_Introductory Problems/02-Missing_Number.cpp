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
	
	//checker
	vector<bool> exist(n+1, false);
	
	//input n-1 numbers
	int number;
	for(int i = 1; i < n; i++) 
	{
		cin >> number;
		exist[number] = true;
	}
	
	//finding the missing number
	for(int i = 1; i <= n; i++) 
	{
		if(!exist[i])
		{
			cout << i << nn;
			break;
		}
	}
}

//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

#define Solutions vector<pair<int,int>>

//solve recursively
void solve(Solutions &sol, int start, int mid, int end, int n)
{
	//base case
	if(n == 1)
	{
		sol.push_back({start, end});
		return;
	}
	
	//move (n-1) topmost from start to mid
	solve(sol, start, end, mid, n-1);
	//move bottom from start to end
	solve(sol, start, mid, end, 1);
	//move the previous (n-1) from mid to end
	solve(sol, mid, start, end, n-1); 
}

int main()
{
	fastio()
	
	//input n
	int n; cin >> n;

	//solve
	Solutions sol;
	solve(sol, 1, 2, 3, n);
	
	//output
	cout << sol.size() << nn;
	for(pair<int,int> i : sol)
	{
		cout << i.first << " " << i.second << nn;
	}
}

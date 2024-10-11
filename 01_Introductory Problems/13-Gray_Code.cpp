//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//solve recursively
vector<string> solve(int n)
{
	//base case
	if(n == 1) return {"0","1"};
	
	//get the valid sequence of n-1
	vector<string> prev = solve(n-1);
		
	//answer
	vector<string> ans;
	
	//prepend with 0 (iterating 1...2^(n-1))
	for(int i = 0; i < prev.size(); i++)
	{
		string cur = "0";
		cur += prev[i];
		ans.push_back(cur);
	}
	//prepend with 1 (iterating 2^(n-1)...1)
	for(int i = prev.size()-1; i >= 0; i--)
	{
		string cur = "1";
		cur += prev[i];
		ans.push_back(cur);
	}
	return ans;
}

int main()
{
	fastio()
	
	//input n
	int n; cin >> n;
	
	//solve
	vector<string> ans = solve(n);
	for(string i : ans) cout << i << nn;
}


//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input string
	string s; cin >> s;
	
	//sort the string
	sort(s.begin(), s.end());	

	vector<string> ans;	
	//use next_permutation()
	do
	{
		ans.push_back(s);
	}while(next_permutation(s.begin(),s.end()));
	
	//output
	cout << ans.size() << nn;
	for(string i : ans) cout << i << nn;
}

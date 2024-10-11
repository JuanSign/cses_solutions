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
	
	//insert every element to a set
	set<int> data;
	int cur;
	for(int i = 0; i < n; i++) 
	{
		cin >> cur;
		data.insert(cur);
	}
	
	//output the size of the set (number of unique elements)
	cout << data.size() << nn;
}

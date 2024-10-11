//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//maintain a multiset that contains all available towers
	multiset<int> towers;
	
	//input data while processing each input
	int n; cin >> n;
	int cur;
	while(n--)
	{
		cin >> cur;
		//find the smallest tower that is greater than cur
		auto it = towers.upper_bound(cur);
		//if it == towers.end() (no towers can be placed under cur)
		//	we build a new tower starting from cur
		//else, we put cur above that tower and update the multiset
		if(it != towers.end()) towers.erase(it);
		towers.insert(cur);
	}
	cout << towers.size() << nn;
}

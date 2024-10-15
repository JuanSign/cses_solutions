//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input data 
	int n,k; cin >> n >> k;
	pair<int,int> films[n];
	for(int i = 0; i < n; i++) cin >> films[i].second >> films[i].first;
	
	//sort films based on ending in ascending order
	sort(films, films+n);
	
	//store ending time in negative
	//create a multiset to store the ending times of each membber
	multiset<int> ending;
	for(int i = 0; i < k; i++) ending.insert(-1);
	
	int ans = 0;
	
	//iterate every movie
	for(int i = 0; i < n; i++)
	{
		//search for the first ending time that is smaller than or equal to current start time
		auto it = ending.lower_bound(-1*films[i].second);
		if(it != ending.end())
		{
			ans++;
			ending.erase(it);
			ending.insert(-1*films[i].first);
		}
	}
	
	cout << ans << nn;
}

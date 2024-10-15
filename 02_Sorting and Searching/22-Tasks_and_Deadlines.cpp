//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
		
	//input tasks and deadlines;
	int n; cin >> n;
	pair<int,int> data[n];
	for(int i = 0; i < n; i++) cin >> data[i].first >> data[i].second;
		
	//sort the data based on the duration in ascending order
	sort(data, data+n);
	
	//declare time and reward
	long long time = 0;
	long long reward = 0;
		
	//process every task
	for(int i = 0; i < n; i++) 
	{
		time += data[i].first;
		reward += (data[i].second - time);
	}	
	
	cout << reward << nn;	
}

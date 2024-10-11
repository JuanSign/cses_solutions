//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	//input n,m
	int n, m; cin >> n >> m;

	//values[i] := value in position i
	//positions[i] := positions of i
	int values[n+1], positions[n+1];
	
	//input data
	for(int i = 1; i <= n; i++)
	{
		cin >> values[i];
		positions[values[i]] = i;
	}
	
	//default sum = 1
	int sum = 1;
	//count sum before swaps
	for(int i = 1; i < n; i++) sum += (positions[i] > positions[i+1]);
	
	while(m--)
	{
		//input swaps
		int left, right;
		cin >> left >> right;
	
		//get all impacted values after swaps	
		set<pair<int,int>> swaps;
		if(values[left] - 1 >= 1) swaps.insert({values[left]-1,values[left]});
		if(values[left] + 1 <= n) swaps.insert({values[left], values[left]+1});
		if(values[right] - 1 >= 1) swaps.insert({values[right]-1,values[right]});
		if(values[right] + 1 <= n) swaps.insert({values[right], values[right]+1});
		
		//reset inversion	
		for(pair<int,int> s : swaps)
		{	
			if(positions[s.first] > positions[s.second]) sum--;
		}	
	
		//swap
		positions[values[left]] = right;
		positions[values[right]] = left;
		swap(values[left], values[right]);
	
		//recalculate inversion
		for(pair<int,int> s : swaps)
		{	
			if(positions[s.first] > positions[s.second]) sum++;
		}
		
		cout << sum << nn;
	}
}

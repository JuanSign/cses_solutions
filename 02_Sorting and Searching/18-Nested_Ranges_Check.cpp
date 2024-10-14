//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()

	//map to store index before sorting
	map<pair<int,int>, int> index;

	//input pairs
	int n; cin >> n;
	pair<int,int> data[n];
	for(int i = 0; i < n; i++)
	{
		cin >> data[i].first >> data[i].second;
		index.insert({data[i],i});
	}
	
	//sort in ascending order based on the first value,
	//if theres exist duplicate first value, sort in descending order based on the second value
	sort(data, data+n, [](const pair<int,int>& a, const pair<int,int>& b)
						  {
						  	if(a.first == b.first) return a.second > b.second;	
							return a.first < b.first;
						  });
	
	//answers array
	int contains[n] = {0};
	int contained[n] = {0};
	
	//iterate from n-1 to 0 (greatest left end to smallest left end)
	//store a variable that holds the smallest right end
	int smallestRight = INT_MAX;
	for(int i = n-1; i >= 0; i--)
	{
		//if the current range right end >= smallestRight 
		//then the current range contains the range that has the smallestRight
		//since the left end of the range that has the smallestRight >= the left end of the current range
		if(data[i].second >= smallestRight) contains[index[data[i]]] = 1;
		else smallestRight = data[i].second;
	}
	
	//iterate from 0 to n-1 (smallest left end to greatest left end)
	//store a variable that holds the largest right end
	int largestRight = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		//if the current range right end <= largestRight 
		//then the current range is contained in the range that has largestRight
		//since the left end of the range that has the largestRight <= the left end of the current range
		if(data[i].second <= largestRight) contained[index[data[i]]] = 1;
		else largestRight = data[i].second;
	}
	
	//output
	for(int i = 0; i < n; i++) cout << contains[i] << " ";
	cout << nn;
	for(int i = 0; i < n; i++) cout << contained[i] << " ";
	cout << nn;
}

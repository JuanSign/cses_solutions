//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

// count range sum in segment tree
int count(int segTree[], int index, int lb, int rb, int L, int R)
{
	if(lb == L && rb == R) return segTree[index];
	if(L > R) return 0;
	int mid = (lb+rb)/2;
	return count(segTree, 2*index+1, lb, mid, L, min(mid, R)) + 
			count(segTree, 2*index+2, mid+1, rb, max(mid+1,L), R);
}

// adding 1 to the given id (index)
void add(int segTree[], int index, int lb, int rb, int id)
{
	if(lb == rb) segTree[index]++;
	else
	{
		int mid = (lb+rb)/2;
		if(id <= mid) add(segTree, 2*index+1, lb, mid, id);
		else add(segTree, 2*index+2, mid+1, rb, id);
		segTree[index] = segTree[2*index+1] + segTree[2*index+2];
	}
}

int main()
{
	fastio()
		
	//input ranges
	int n; cin >> n;
	vector<pair<int,int>> data(n);
	int rightEnd[n]; //keep track of all right ends
	//map ranges to its index
	map<pair<int,int>,int> rangeIndex;
	//input
	for(int i = 0; i < n; i++) 
	{
		cin >> data[i].first >> data[i].second;
		//range 
		rangeIndex[data[i]] = i;
		//keep track of all right ends for coordinate compression
		rightEnd[i] = data[i].second;
	}
			
	//coordinate compression
	unordered_map<int,int> compIndex;
	int curIndex = 0;
	sort(rightEnd, rightEnd+n);
	for(int i = 0; i < n; i++) 
		if(!compIndex[rightEnd[i]]) compIndex[rightEnd[i]] = ++curIndex;
	
	//sort the ranges in ascending order of the first value, then descending order of the second value
	sort(data.begin(), data.end(),   [](const pair<int,int>& a, const pair<int,int>& b)
						 			 {
								     	if(a.first == b.first) return a.second > b.second;
										return a.first < b.first;
									 });
	
	//segment tree
	int segTree[4*curIndex];
	//answer's array
	int contains[n], contained[n];
		 
	//solving (same approach as in 18-Nested_Ranges_Check.cpp)
	for(int i = 0; i < 4*curIndex; i++) segTree[i] = 0;
	for(int i = n-1; i >= 0; i--)
	{
		contains[rangeIndex[data[i]]] = count(segTree, 0, 0, curIndex-1, 0, compIndex[data[i].second]-1);
		add(segTree, 0, 0, curIndex-1, compIndex[data[i].second]-1);
	}
	for(int i = 0; i < 4*curIndex; i++) segTree[i] = 0;
	for(int i = 0; i < n; i++)
	{
		contained[rangeIndex[data[i]]] = count(segTree, 0, 0, curIndex-1, compIndex[data[i].second]-1, curIndex-1);
		add(segTree, 0, 0, curIndex-1, compIndex[data[i].second]-1);
	}
	
	//output
	for(int i = 0; i < n; i++) cout << contains[i] << " ";
	cout << nn;
	for(int i = 0; i < n; i++) cout << contained[i] << " ";
	cout << nn;
	
}

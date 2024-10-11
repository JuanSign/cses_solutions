//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	//input n,k
	int n,k; cin >> n >> k;
	
	//partitions an array of n elements into x smaller subarray with size <= sqrt(n)
	int maxSize = sqrt(n);
	
	vector<vector<int>> data;
	vector<int> subArr;
	
	int curSize = 0;
	for(int i = 1; i <= n; i++)
	{
		subArr.push_back(i);
		curSize++;
		if(curSize == maxSize)
		{
			data.push_back(subArr);
			subArr.clear();
			curSize = 0;
		}
	}
	if(!subArr.empty()) data.push_back(subArr);
	
	//simulation in O(n*sqrt(n))
	
	//initial position
	int row = 0;
	int col = 0;
	int steps;
	for(int i = n; i > 0; i--)
	{
		//calculate steps
		steps = k%i;
		//skip row until we land on the right row	
		while(steps >= (int)data[row].size()-col)
		{	
			steps -= (int)(data[row].size()-col);
			row++;
			row%=(int)data.size();
			col = 0;
		}
		//update col value
		col += steps;
		//output the correct value
		cout << data[row][col] << " ";
		//erase that value
		data[row].erase(data[row].begin()+col);
		//update col
		if(col == (int)data[row].size())
		{
			col = 0;
			row++;
			row%=data.size();
		}
	}
}

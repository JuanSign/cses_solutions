//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input data
	int n; cin >> n;
	int data[n];
	for(int i = 0; i < n; i++) cin >> data[i];
		
	//maintain a stack to store the nearest smallest
	stack<pair<int,int>> passed;
	
	//process data from left to right
	for(int i = 0; i < n; i++)
	{
		//if the passed stack is empty and the top element is bigger than the data processed
		while(!passed.empty() && passed.top().first >= data[i]) passed.pop();
		//if the resulting stack is empty, cout 0
		if(passed.empty()) cout << 0 << " ";
		//if not, output the top
		else cout << passed.top().second << " ";
		//insert current value and index to stack
		passed.push({data[i], i+1});
	}
}

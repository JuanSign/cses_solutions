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
	
	//the longest sequence will start from index (start)
	int start = 0;	
	set<int> sequence;
	
	int ans = INT_MIN;
	
	for(int i = 0; i < n; i++)
	{
		while(sequence.count(data[i])) sequence.erase(data[start++]);
		sequence.insert(data[i]);	
		ans = max(ans, (int)sequence.size());
	}
	
	cout << ans << nn;
}

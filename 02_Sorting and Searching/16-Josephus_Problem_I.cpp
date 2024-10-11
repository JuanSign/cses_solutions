//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	//simulate with a queue
	int n; cin >> n;
	queue<int> list;
	for(int i = 1; i <= n; i++) list.push(i);
	for(int i = 0; i < n; i++) 
	{	
		list.push(list.front());
		list.pop();
		cout << list.front() << " ";
		list.pop();
	}
}

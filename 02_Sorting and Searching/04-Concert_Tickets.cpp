//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
		
	//input data
	int n, m; cin >> n >> m;
	
	//store ticket price in a multiset
	multiset<int> tickets;
	int tick;
	for(int i = 0; i < n; i++)
	{
		cin >> tick;
		tickets.insert(tick);
	}
	
	//processing customers
	int cust;
	for(int i = 0; i < m; i++)
	{
		cin >> cust;
		//find the first ticket that is greater than cust
		auto it = tickets.upper_bound(cust);
		
		//if theres exist a ticket cheaper than it, output
		if(it != tickets.begin())
		{	
			it--;
			cout << *it << nn;
			//erase the ticket
			tickets.erase(it);
		}
		else cout << -1 << nn;
	}
}

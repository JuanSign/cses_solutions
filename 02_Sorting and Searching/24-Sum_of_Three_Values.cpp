//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//solve
void solve(int n, int x, pair<int,int> data[])
{
	for(int a1 = 0; a1 < n-2; a1++)
	{
		int a2 = a1+1;
		int a3 = n-1;
		while(a2 < a3)
		{
			int sum = data[a1].first + data[a2].first + data[a3].first;
			if(sum == x) 
			{	
				cout << data[a1].second << " " << data[a2].second << " " << data[a3].second << nn;		
				return;
			}
			else if(sum < x) a2++;
			else if(sum > x) a3--;
		}
	}
	cout << "IMPOSSIBLE" << nn;
	return;
}

int main()
{
	fastio()
	
	//input data
	int n, x; cin >> n >> x;
	pair<int,int> data[n];
	for(int i = 0; i < n; i++) 
	{
		cin >> data[i].first;
		//index
		data[i].second = i+1;
	}
	
	//sort data
	sort(data, data+n);
	
	//solve
	solve(n, x, data);
}

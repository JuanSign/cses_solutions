//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//solve
void solve(int n, int x, pair<int,int> data[])
{
	for(int a1 = 0; a1 < n-3; a1++)
	{
		for(int a2 = a1+1; a2 < n-2; a2++)
		{
			int a3 = a2+1;
			int a4 = n-1;
			while(a3 < a4)	
			{
				int sum = data[a1].first + data[a2].first + data[a3].first + data[a4].first;
				if(sum == x)
				{
					cout << data[a1].second << " " << data[a2].second << " ";
					cout << data[a3].second << " " << data[a4].second << nn;
					return;
				}
				else if(sum < x) a3++;
				else if(sum > x) a4--;
			}
		}
	}
	cout << "IMPOSSIBLE" << nn;
	return;
}

int main()
{
	fastio()
	
	//same approach as the (24-Sum_of_Three_Values.cpp)
	int n, x; cin >> n >> x;
	pair<int,int> data[n];
	for(int i = 0; i < n; i++) 
	{
		cin >> data[i].first;
		data[i].second = i+1;
	}
	
	//sort data
	sort(data, data+n);
	
	//solve
	solve(n, x, data);
}

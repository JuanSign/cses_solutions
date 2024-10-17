//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n,m
	int n,m; cin >> n >> m;
	
	//input building
	string building[n];
	for(int i = 0; i < n; i++) cin >> building[i];	
		
	//declare room count
	int count = 0;
	
	//start bfs on every '.' cell
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(building[i][j] != '#')
			{
				//increment count
				count++;
				
				//start bfs
				queue<pair<int,int>> q;
				q.push({i,j});
	
				while(!q.empty())
				{
					pair<int,int> cur = q.front();
					q.pop();
					//if visiting a wall, continue
					if(building[cur.first][cur.second] == '#') continue;
					
					//check all possible neighbors
					if(cur.first+1 < n) q.push({cur.first+1,cur.second});
					if(cur.first-1 >= 0) q.push({cur.first-1,cur.second});
					if(cur.second+1 < m) q.push({cur.first,cur.second+1});					
					if(cur.second-1 >= 0) q.push({cur.first,cur.second-1});

					//mark visited
					building[cur.first][cur.second] = '#';
				}
			}
		}
	}
	cout << count << nn;
}

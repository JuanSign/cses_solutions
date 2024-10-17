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
	
	//create adjacency list
	vector<vector<int>> adj(n+1);
	//par[i] := parent node of node i (-1 if not reached yet)
	vector<int> par(n+1,-1);
	
	//input edges
	for(int i = 0; i < m; i++)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
		
	//start bfs from 1
	queue<int> q;
	
	q.push(1);
	par[1] = 1;	

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		if(cur == n) break;
		for(int child : adj[cur])
		{
			if(par[child] == -1)
			{
				par[child] = cur;
				q.push(child);
			}
		}
	}

	//check if n is reached
	if(par[n] != -1)
	{
		//generate path
		vector<int> path;	
	
		int cur = n;
		while(par[cur] != cur)
		{
			path.push_back(cur);
			cur = par[cur];
		}	
		path.push_back(cur);
	
		cout << path.size() << nn;
		for(int i = (int)path.size()-1; i >= 0; i--) cout << path[i] << " ";
		cout << nn;
	}
	else cout << "IMPOSSIBLE" << nn;






	
	
	
}

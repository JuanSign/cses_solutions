//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n and m
	int n,m; cin >> n >> m;
		
	//create required data
	vector<vector<int>> adj(n+1);
	vector<bool> visited(n+1, false);
	vector<int> parent(n+1,-1);
	
	//input edges
	for(int i = 0; i < m; i++)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	//since distance is irrelevant, bfs is good enough
	queue<int> q;
	q.push(1);
	parent[1] = 1;
	
	//bfs
	while(!q.empty())	
	{
		int cur = q.front();
		q.pop();
		visited[cur] = true;
		if(cur == n) break;
		for(int child : adj[cur])
		{
			if(!visited[child]) 
			{
				q.push(child);
				visited[child] = true;
				parent[child] = cur;
			}
		}
	}
	
	//check if n is visited
	if(visited[n])
	{
		//generate path
		vector<int> path;
		int cur = n;
		while(parent[cur] != cur)
		{
			path.push_back(cur);
			cur = parent[cur];
		}

		//output
		cout << path.size()+1 << nn;
		reverse(path.begin(),path.end());
		cout << 1 << " ";
		for(int i : path) cout << i << " ";
	}
	else cout << "IMPOSSIBLE" << nn;
}

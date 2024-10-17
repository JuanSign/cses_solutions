//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//adjacency list
vector<vector<int>> adj;
//visited vector
vector<bool> vis;
//representation of each disjoint graph
vector<int> graph;

//recursive dfs
void dfs(int i)
{
	vis[i] = true;
	for(int child : adj[i])
	{
		if(!vis[child]) dfs(child);
	}
}


int main()
{
	fastio()
	
	//input n,m
	int n,m; cin >> n >> m;
	
	//resizing
	adj.resize(n+1);
	vis.resize(n+1, false);
		
	//input edges
	for(int i = 0; i < m; i++)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	

	//start dfs from each unvisited node
	for(int i = 1; i <= n; i++)
		if(!vis[i]) 
		{
			graph.push_back(i);
			dfs(i);
		}
	
	//output
	cout << graph.size()-1 << nn;
	for(int i = 1; i < (int)graph.size(); i++)
		cout << graph[0] << " " << graph[i] << nn;
}

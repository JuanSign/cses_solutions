//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//declare as global
vector<vector<int>> adj;
vector<bool> visited;
vector<int> graph;

//recursive dfs
void dfs(int i)
{
	visited[i] = true;
	for(int child : adj[i])
	{
		if(!visited[child]) dfs(child);
	}
}

int main()
{
	fastio()
	
	//input n and m
	int n,m; cin >> n >> m;
	
	//resize 
	adj.resize(n+1);
	visited.resize(n+1);
	
	//input edges
	for(int i = 0; i < m; i++)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	//run dfs on every unvisited node
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			graph.push_back(i);
			dfs(i);
		}
	}
	
	cout << graph.size()-1 << nn;
	for(int i = 1; i < (int)graph.size(); i++)
	{	
		//connect every graph to the first graph
		cout << graph[0] << " " << graph[i] << nn;
	}

}

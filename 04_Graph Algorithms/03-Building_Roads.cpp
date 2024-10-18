//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//N := number of cities
//M := number of roads
//graph[i][j] := the j-th road in city-i
//vis[i] := true if city-i is visited, false otherwise
//comp[i] := store the city that represents the i-th component of the graph

int N, M;
vector<vector<int>> graph;
vector<bool> vis;
vector<int> comp;

//recursive dfs
void dfs(int i)
{
	vis[i] = true;
	for(int c : graph[i])
		if(!vis[c]) dfs(c);
}

int main()
{
	fastio()

	//input N and M
	cin >> N >> M;
	
	//resizing
	graph.resize(N+1); //1-indexing
	vis.resize(N+1, false); //1-indexing
	
	//input roads
	for(int i = 0; i < M; i++)
	{
		int a,b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	//dfs on every unvisited nodes;
	for(int i = 1; i <= N; i++)		
	{
		if(!vis[i])
		{
			comp.push_back(i);
			dfs(i);
		}
	}
	
	//output
	cout << (int)comp.size()-1 << nn;
	//output a road that connects every component
	for(int i = 1; i < (int)comp.size(); i++) cout << comp[0] << " " << comp[i] << nn;
}

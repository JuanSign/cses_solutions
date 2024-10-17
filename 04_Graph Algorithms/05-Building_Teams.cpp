//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//adjacency list
vector<vector<int>> adj;
//visited and team vector
vector<bool> vis, team;
//condition checker
bool possible = true;

//recursive dfs (current, parent)
void dfs(int cur, int par = 0)
{
	//mark visited
	vis[cur] = true;
	
	//check every neighbor
	for(int child : adj[cur])
	{
		//avoid backtrack
		if(child != par)
		{
			//if not visited
			if(!vis[child])
			{
				//assign to different team
				team[child] = !team[cur];
				//start recursion
				dfs(child,cur);
			}
			else
			{
				//check if in the same team
				if(team[child] == team[cur]) possible = false;
			}
		}
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
	team.resize(n+1, false);
	
	//input edges
	for(int i = 0; i < m; i++)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//dfs on every unvisited node
	for(int i = 1; i <= n; i++)
		if(!vis[i]) dfs(i);	

	if(possible)
	{
		for(int i = 1; i <= n; i++) cout << 1+team[i] << " ";
		cout << nn;
	}
	else cout << "IMPOSSIBLE" << nn;

}

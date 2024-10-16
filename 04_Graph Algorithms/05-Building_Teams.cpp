//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//declare global
vector<vector<int>> adj;
vector<bool> vis;
vector<bool> team;
bool possible = true;

//recursive dfs
void dfs(int cur, int parent = 0)
{
	//iterate every child(neighbor) of cur
	for(int child : adj[cur])
	{
		//if not a cycle
		if(child != parent)
		{
			//if child not visited
			if(!vis[child])
			{
				//mark visited
				vis[child] = true;
				//put in different team than parent
				team[child] = !team[cur];
				//dfs from child
				dfs(child, cur);
			}
			else
			{	
				//if child and parent in the same team, then impossible
				if(team[child] == team[cur]) possible = false;
			}
		}
	}
}

int main()
{
	fastio()
	
	//input n m
	int n,m; cin >> n >> m;
	//resize vector
	adj.resize(n+1);
	vis.resize(n+1,false);
	team.resize(n+1,false);
	
	//input edges
	for(int i = 0; i < m; i++)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			vis[i] = true;
			dfs(i);
		}
	}
	
	if(!possible) cout << "IMPOSSIBLE" << nn;
	else
	{
		for(int i = 1; i <= n; i++) cout << 1+team[i] << " ";
	}
}

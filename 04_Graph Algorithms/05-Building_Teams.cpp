//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//N := number of pupils
//M := number of friendships (connections)
//con[i][j] := the j-th connection of the i-th pupil
//team[i] := true if the i-th pupil is in team 1, false otherwise
//vis[i] := true if the i-th pupil is visited, false otherwise
//possible := true if possible to fulfill the condition, false otherwise

int N, M;
vector<vector<int>> con;
vector<bool> team, vis;
bool possible = true; //assume true

//recursive dfs(current, parent)
void dfs(int c, int p = 0) //default value 0
{
	vis[c] = true;
	for(int n : con[c])
	{
		//check all neighbor that is not the parent
		if(n == p) continue;
		//if neighbor is not visited yet
		if(!vis[n])
		{
			//assign to different team
			team[n] = !team[c];
			//start dfs from that node
			dfs(n,c);
		}
		else
		{
			//if node is already visited and in the same team as c
			//impossible
			if(team[n] == team[c]) possible = false;
		}
	}
}

int main()
{
	fastio()
	
	//input N and M
	cin >> N >> M;
	
	//resizing
	con.resize(N+1);
	team.resize(N+1, false); //initially all false
	vis.resize(N+1, false); //initially all false	
	
	//input all friendships
	for(int i = 0; i < M; i++)
	{
		int a,b; cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	
	//run dfs on every unvisited node
	for(int i = 1; i <= N; i++)
		if(!vis[i]) dfs(i);
	
	//check possibility
	if(possible)
	{
		//output answer
		for(int i = 1 ; i <= N; i++) cout << 1+team[i] << " ";
		cout << nn;
	}
	else cout << "IMPOSSIBLE" << nn;
}

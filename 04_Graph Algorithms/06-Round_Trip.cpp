//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//N := number of cities
//M := number of roads
//city[i][j] := the j-th road of city-i
//vis[i] := true if city-i is visited, false otherwise
//par[i] := parent of city-i
//sC := start city of the selected cycle
//eC := end city of the selected cycle

int N, M;
vector<vector<int>> city;
vector<bool> vis;
vector<int> par;
int sC, eC;

//recursive dfs(current,parent) that traverse the graph
//and returns true if detected a cycle
bool dfs(int c, int p = -1)
{
	vis[c] = true;
	par[c] = p;
	for(int n : city[c])
	{
		//check all node that is not the parent
		if(n == p) continue;

		//if n is already visited, we found a cycle!
		if(vis[n])
		{
			//the cycle start from n all the way to c and back to n
			sC = n;
			eC = c;
			//return true to notify that we have found a cycle
			return true;
		}
		else
		{
			//if unvisited, we run dfs from this node
			if(dfs(n,c)) 
			{
				//if the dfs returning true, we forward the message
				return true;
			}
		}
	}
	//return false
	return false;
}

//check cycle
bool CheckCycle()
{
	//run dfs on every unvisited node
	for(int i = 1; i <= N; i++)
	{
		if(!vis[i])
		{
			//if the dfs returning true, we forward the message
			if(dfs(i)) return true;
		}
	}
	return false;
}

int main()
{
	fastio()

	//input N and M
	cin >> N >> M;
	
	//resizing
	city.resize(N+1);
	vis.resize(N+1, false); //initially all false
	par.resize(N+1, false); //initially all false
	
	//input all roads
	for(int i = 0; i < M; i++)
	{
		int a,b; cin >> a >> b;
		city[a].push_back(b);
		city[b].push_back(a);
	}
	
	//check for cycle
	if(CheckCycle())
	{
		//generate path
		deque<int> path;	
	
		//insert starting city
		path.push_front(sC);
			
		//start from ending city
		int cC = eC;
		while(cC != sC)
		{
			path.push_front(cC);
			cC = par[cC];
		}
	
		//insert starting city
		path.push_front(sC);
	
		//output	
		cout << (int)path.size() << nn;	
		while(!path.empty()) 
		{
			cout << path.front() << " ";
			path.pop_front();
		}
		cout << nn;
	}
	else cout << "IMPOSSIBLE" << nn;
}

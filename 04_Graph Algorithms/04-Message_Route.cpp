//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//N := number of computers
//M := number of connections
//con[i][j] := the j-th connection of the i-th computer
//vis[i] := true if the i-th computer is visited, otherwise false
//par[i] := parent of computer-i
//S := start computer
//E := end computer

int N, M;
vector<vector<int>> con;
vector<int> par;
vector<bool> vis;
int S,E;

void bfs()
{
	//create bfs queue
	queue<int> q;
		
	//insert source to q
	q.push(S);
	//mark source as visited
	vis[S] = true;
	
	//bfs
	while(!q.empty())
	{
		//current computer
		int cC = q.front();
		q.pop();
		//check end condition
		if(cC == E) break;
	
		//push all unvisited neighbor to queue
		for(int uN : con[cC])
		{
			if(!vis[uN])
			{
				vis[uN] = true;
				par[uN] = cC;
				q.push(uN);
			}
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
	par.resize(N+1, -1); //initially all -1
	vis.resize(N+1, false);
	
	//input all connections
	for(int i = 0; i < M; i++)
	{
		int a,b; cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	
	//start bfs from 1
	S = 1;
	E = N;
	bfs();
	
	//check if E has a parent
	if(par[E] != -1)
	{
		//generate path
		deque<int> path;
	
		int cC = E;
		while(par[cC] != -1)
		{
			path.push_front(cC);
			cC = par[cC];		
		}
		path.push_front(S);
		
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

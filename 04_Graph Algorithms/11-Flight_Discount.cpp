//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//path
#define Path tuple<long long, int, int>
//edge
#define Edge pair<int, int>

//N := number of cities
//M := number of connections
//graph := adjacency list
//dis[N+1][2] := distance vector
//vis[N+1][2] := visited vector

int N, M;
vector<vector<Edge>> graph;
vector<vector<long long>> dis;
vector<vector<bool>> vis;

void dijkstra()
{
	//create prio queue
	priority_queue<Path, vector<Path>, greater<Path>> pq;
	
	//insert 1 to pq
	pq.push({0,1,0});
	dis[1][0] = 0;
	dis[1][1] = 0;
	
	while(!pq.empty())
	{
		Path cur = pq.top();
		pq.pop();
		int cC = get<1>(cur);
		long long cD = get<0>(cur);
		int cS = get<2>(cur);
		
		if(vis[cC][cS]) continue;
		vis[cC][cS] = true;
	
		for(Edge e : graph[cC])
		{
			int nC = e.first;
			long long nD = e.second;
	
			//insert normal price	
			if(!vis[nC][cS])
			{
				if(dis[nC][cS] > dis[cC][cS] + nD)
				{
					dis[nC][cS] = dis[cC][cS] + nD;
					pq.push({dis[nC][cS], nC, cS});
				}
			}
	
			//insert discounted price (if possible)
			if(!cS)
			{
				if(!vis[nC][1])
				{
					if(dis[nC][1] > dis[cC][0] + nD/2)
					{
						dis[nC][1] = dis[cC][0] + nD/2;
						pq.push({dis[nC][1], nC, 1});
					}
				}
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
	graph.resize(N+1);
	dis.resize(N+1, vector<long long>(2, LONG_LONG_MAX));	
	vis.resize(N+1, vector<bool>(2, false));
	
	//input edges
	for(int i = 0; i < M; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		graph[a].push_back({b,c});
	}
	
	//modified dijkstra
	dijkstra();
	
	//output best price with discount
	cout << dis[N][1] << nn;
}

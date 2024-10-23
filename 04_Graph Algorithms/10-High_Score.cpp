//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

struct Edge{
	int a,b;
	long long c;
};

//N := number of rooms
//M := number of tunnels
//edges := vector of Edge
//dist := vector of distance
//isInf := whether a room can be reached in INF score or not

int N, M;
vector<Edge> edges;
vector<long long> dist;
vector<bool> isInf;

void solve()
{
	dist[1] = 0;
	
	for(int i = 1; i <= 2*N; i++)
	{
		for(Edge e : edges)
		{
			if(i <= N)
			{
				if(dist[e.a] > LONG_LONG_MIN)
				{	
					if(dist[e.b] < dist[e.a] + e.c) 
						dist[e.b] = dist[e.a] + e.c;
				}
			}
			else
			{
				if(isInf[e.a]) isInf[e.b] = true;
				if(dist[e.a] > LONG_LONG_MIN)
				{
					if(dist[e.b] < dist[e.a] + e.c)
					{
						dist[e.b] = dist[e.a] + e.c;
						isInf[e.b] = true;
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
	edges.resize(M);
	dist.resize(N+1, LONG_LONG_MIN);
	isInf.resize(N+1, false);
	
	//input edges
	for(int i = 0; i < M; i++) cin >> edges[i].a >> edges[i].b >> edges[i].c;
	
	solve();
	
	if(!isInf[N]) cout << dist[N] << nn;
	else cout << -1 << nn;
}

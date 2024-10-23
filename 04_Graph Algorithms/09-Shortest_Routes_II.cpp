//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//N := number of cities
//M := number of roads
//q := number of queries
//dist[i][j] := shortest distance from city-i to city-j

int N, M;
int q;
vector<vector<long long>> dist;

int main()
{
	fastio()
	
	//input N, M, and q
	cin >> N >> M >> q;
	
	//resizing
	dist.resize(N+1, vector<long long>(N+1, LONG_LONG_MAX));
	
	//input all edges
	for(int i = 0; i < M; i++)
	{
		int from, to, weight; 
		cin >> from >> to >> weight;
		dist[from][to] = min(dist[from][to],(long long)weight);
		dist[to][from] = min(dist[to][from],(long long)weight);
	}	
		
	//dist[i][i] = 0 for all i
	for(int i = 1; i <= N; i++) dist[i][i] = 0;
	
	//floyd-warshall
	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(dist[i][k] == LONG_LONG_MAX || dist[k][j] == LONG_LONG_MAX)
					continue;
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	
	//process queries
	while(q--)
	{
		int from, to; cin >> from >> to;
		if(dist[from][to] == LONG_LONG_MAX) cout << -1 << nn;
		else cout << dist[from][to] << nn;
	}
}

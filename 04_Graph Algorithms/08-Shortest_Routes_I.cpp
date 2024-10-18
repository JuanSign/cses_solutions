//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//Edge {weight,destination}
#define Edge pair<long long,int>

//N := number of cities
//M := number of flight connections
//graph[i][j] := the j-th flight connection (Edge) from city-i
//dist[i] := the distance from city-1 to city-i
//vis[i] := true if city-i is already visited by dijkstra's algo
 
int N;
int M;
vector<vector<Edge>> graph;
vector<long long> dist;
vector<bool> vis;

//dijkstra's algorithm
void dijkstra(int source)
{
	//create prio queue
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	
	//insert source city to pq
	pq.push({0,source});
	//update distance of source
	dist[source] = 0;
	
	//start dijkstra
	while(!pq.empty())
	{
		//current city
		int cC = pq.top().second;
		//current distance
		long long cD = pq.top().first;
		//remove from pq
		pq.pop();
		//if city is already visited, skip
		if(vis[cC]) continue;
		//mark as visited
		vis[cC] = true;
		
		//update distance from all neighbors
		for(Edge e : graph[cC])
		{
			//neighbor city
			int nC = e.second;
			//distance to that neighbor
			long long nD = e.first;
			//if neighbor is not visited yet...
			if(!vis[nC])
			{
				//check new distance
				long long nDst = cD + nD;
				//if new distance is better...
				if(nDst < dist[nC])
				{
					//update distance
					dist[nC] = nDst;
					//insert to pq
					pq.push({dist[nC],nC});
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
	dist.resize(N+1, LONG_LONG_MAX); //initially all infinite
	vis.resize(N+1, false); //initially all unvisited

	//input all flight connections
	for(int i = 0; i < M; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({weight,to});
	}
		
	//start dijkstra's algo from city-1
	dijkstra(1);
	
	//output distance
	for(int i = 1; i <= N; i++) cout << dist[i] << " ";
}

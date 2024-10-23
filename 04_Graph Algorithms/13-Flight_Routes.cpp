//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//edges
#define Edge pair<long long, int>

//N := number of cities
//M := number of flights
//K := requested number of shortest path
//grp := graph (adjacency list)
//rgrp := reverse graph
//d1 := d1[i] shortest distance from 1 to i
//d2 := d2[i] shortest distance from i to N
//vis1 := visited vector
//vis2 := visited vector

int N, M, K;
vector<vector<Edge>> grp, rgrp;
vector<long long> d1, d2;
vector<bool> vis1, vis2;

void dijkstra(int i)
{
	int s;
	if(i == 1) s = 1;
	if(i == 2) s = N;
	
	//create priority queue
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	
	//insert source to pq
	pq.push({0,s});
	if(i == 1) d1[s] = 0;
	if(i == 2) d2[s] = 0;

	while(!pq.empty())
	{
		int cN = pq.top().second;
		pq.pop();
		if(i == 1 && vis1[cN]) continue;
		if(i == 2 && vis2[cN]) continue;
		if(i == 1) vis1[cN] = true;
		if(i == 2) vis2[cN] = true;
	
		vector<Edge> edges;
		if(i == 1) edges = grp[cN];
		if(i == 2) edges = rgrp[cN];
	
		for(Edge e : edges)
		{
			int nN = e.second;
			long long nD = e.first;
			if(i == 1 && vis1[nN]) continue;
			if(i == 2 && vis2[nN]) continue;
			if(i == 1 && (d1[nN] > d1[cN] + nD))
			{
				d1[nN] = d1[cN] + nD;
				pq.push({d1[nN], nN});
			}	
			if(i == 2 && (d2[nN] > d2[cN] + nD))
			{
				d2[nN] = d2[cN] + nD;
				pq.push({d2[nN], nN});
			}
		}
	}
	
}

int main()
{
	fastio()

	//input N and M
	cin >> N >> M >> K;
	
	//resizing
	grp.resize(N+1);
	rgrp.resize(N+1);
	d1.resize(N+1, LONG_LONG_MAX);
	d2.resize(N+1, LONG_LONG_MAX);
	vis1.resize(N+1, false);
	vis2.resize(N+1, false);
	
	//input edges
	for(int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		grp[a].push_back({c,b});
		rgrp[b].push_back({c,a});
	}	

	//dijkstra 1 and 2
	dijkstra(1);
	dijkstra(2);
	
	vector<long long> distance;
	for(int i = 1; i <= N; i++)
	{
		if(vis1[i] && vis2[i])
		{
			cout << i << " " << d1[i] << " " << d2[i] << nn;
			distance.push_back(d1[i]+d2[i]);
		}
	}
	
	sort(distance.begin(), distance.end());
	for(int i = 0; i < K; i++) cout << distance[i] << " ";
}

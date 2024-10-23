//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//edge
#define Edge pair<int, long long>

//N := number of nodes
//M := number of edges
//grph := adjacency list
//dis := distance vector
//vis := vis[i] is the itaration where node i is first visited
//cnt := count vector;
//par := parent vector;
//inQ := checker if inQ[i] is currently in queue or not
//X := a node on the negative cycle (if exist)

int N, M;
vector<vector<Edge>> grph;
vector<long long> dis;
vector<int> vis, cnt, par;
vector<bool> inQ;
int X = -1;

bool SPFA(int i)
{
	queue<int> q;
	//distance to source is 0
	dis[i] = 0;
	
	//push to queue
	q.push(i);
	inQ[i] = true;
	
	while(!q.empty())
	{
		int cN = q.front();
		long long cD = dis[cN];
		q.pop();
		inQ[cN] = false;
		vis[cN] = i;	
		for(Edge e : grph[cN])
		{
			int nN = e.first;	
			long long nD = e.second;
			if(vis[nN] < i) continue;
			if(dis[cN] + nD < dis[nN])
			{
				dis[nN] = dis[cN] + nD;
				par[nN] = cN;
				if(!inQ[nN])
				{
					q.push(nN);
					inQ[nN] = true;
					cnt[nN]++;
					if(cnt[nN] > N)
					{
						X = nN;
						par[nN] = cN;
						return true;
					}
				}
			}
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
	grph.resize(N+1);
	dis.resize(N+1, LONG_LONG_MAX);
	vis.resize(N+1, INT_MAX);
	cnt.resize(N+1, 0);
	par.resize(N+1, -1);
	inQ.resize(N+1, false);	

	//input edges
	for(int i = 0; i < M; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		grph[a].push_back({b,c});
	}
		
	//run SPFA on every unvisited nodes
	for(int i = 1; i <= N; i++)
	{
		if(i < vis[i]) if(SPFA(i)) break;
	}
	
	//check if a negative cycle exist
	if(X != -1)
	{
		//go back N times to guarantee X lies on a negative cycle
		for(int i = 0; i < N; i++) X = par[X];
	
		//path
		vector<int> path;
		
		int cur = par[X];
		path.push_back(X);
		while(cur != X)
		{
			path.push_back(cur);
			cur = par[cur];
		}
		path.push_back(X);
		
		cout << "YES" << nn;
		reverse(path.begin(), path.end());
		for(int i : path) cout << i << " ";
	}	
	else cout << "NO" << nn;
}


//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n,m
	int n,m; cin >> n >> m;
	
	//input labyrinth
	string laby[n];
	for(int i = 0; i < n; i++) cin >> laby[i];
	
	//find A and B
	pair<int,int> A,B;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(laby[i][j] == 'A') A = {i,j};
			if(laby[i][j] == 'B') B = {i,j};
		}
	}
	
	//since every edge cost is the same
	//we can use bfs
	
	//bfs queue
	queue<pair<int,int>> q;
	map<pair<int,int>,pair<int,int>> par; //map a coordinate to its parent
	
	//start bfs from A
	q.push(A);

	//directions array
	int dirX[] = {0,1,0,-1};
	int dirY[] = {-1,0,1,0};
	
	//bfs loop
	while(!q.empty())
	{
		pair<int,int> cur = q.front();
		q.pop();
		if(laby[cur.first][cur.second] == '#') continue;
		if(cur == B) break; //reached B
		for(int i = 0; i < 4; i++)
		{
			pair<int,int> child = {cur.first+dirY[i],cur.second+dirX[i]};		
			if(child.first < 0   || 
			   child.first >= n  || 
			   child.second < 0  || 
			   child.second >= m || 
			   laby[child.first][child.second] == '#') continue;
	
			q.push(child);
			par.insert({child,cur});
		}
		//mark visited
		laby[cur.first][cur.second] = '#';
	}

	//check if B has a parent
	if(par.find(B) != par.end())
	{
		cout << "YES" << nn;
		//generate path
		string path = "";
		pair<int,int> cur = B;
		while(par.find(cur) != par.end())
		{
			pair<int,int> prt = par[cur];
			if(cur.first > prt.first) path += 'D';
			else if(cur.first < prt.first) path += 'U';
			else
			{
				if(cur.second > prt.second) path += 'R';
				else path += 'L';
			}
			//assign cur to its parent
			cur = prt;
		}
	
		//output
		cout << path.length() << nn;
		for(int i = (int)path.length()-1; i >= 0; i--) cout << path[i];
		cout << nn;
	}
	else cout << "NO" << nn;













}

//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//insert data
	int n, m; cin >> n >> m;
	string nmap[n];
	for(int i = 0; i < n; i++) cin >> nmap[i];
	
	//find the position of A and B
	pair<int,int> A, B;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(nmap[i][j] == 'A') A = {i,j};
			if(nmap[i][j] == 'B') B = {i,j};
		}
	
	//since every distance is 1, bfs is as good as dijkstra
	//bfs queue
	queue<pair<int,int>> q;
	
	//map coordinate to its parent
	map<pair<int,int>,pair<int,int>> getParent;

	//bfs direction
	int dirX[] = {0,1,0,-1};
	int dirY[] = {-1,0,1,0};
	
	//start bfs
	q.push(A);
	
	while(!q.empty())
	{
		pair<int,int> cur = q.front();
		q.pop();
		if(nmap[cur.first][cur.second] == '#') continue;
		
		//visit neighbor
		for(int i = 0; i < 4; i++)
		{
			pair<int,int> neg = {cur.first+dirY[i], cur.second+dirX[i]};
			//if neighbor is visitable
			if(neg.first >= 0 && neg.first < n && neg.second >= 0 && neg.second < m)
			{
				if(nmap[neg.first][neg.second] != '#')
				{
					//push neg to q
					q.push(neg);
					//update parents
					getParent.insert({neg,cur});
				}
			}
		}
		//mark visited
		nmap[cur.first][cur.second] = '#';
	}	

	//check if B has a parent
	if(getParent.find(B) != getParent.end())
	{
		cout << "YES" << nn;
		string path = "";
		pair<int,int> cur = B;
	
		//generate path
		while(getParent.find(cur) != getParent.end())
		{
			pair<int,int> par = getParent[cur];
			if(cur.first > par.first) path += 'D';
			else if(cur.first < par.first) path += 'U';
			else
			{
				if(cur.second > par.second) path += 'R';
				else path += 'L';
			}
			cur = par;
		}
		cout << path.size() << nn;
		reverse(path.begin(),path.end());
		cout << path << nn;
	}
	else cout << "NO" << nn;
}

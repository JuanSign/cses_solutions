//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input data
	int row, col; cin >> row >> col;
	string map[row];
	for(int i = 0; i < row; i++) cin >> map[i];
	
	int ans = 0;	

	//iterate every cell	
	//increment count then start bfs on a cell that is not '#'
	//change the value of visited cell with '#'
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(map[i][j] == '#') continue;
			//increment ans
			ans++;
			//bfs
			queue<pair<int,int>> q;
			q.push({i,j});
	
			while(!q.empty())
			{
				pair<int,int> cur = q.front();
				q.pop();
				if(map[cur.first][cur.second] == '#') continue;
	
				if(cur.first-1 >= 0) q.push({cur.first-1,cur.second});
				if(cur.second+1 < col) q.push({cur.first,cur.second+1});
				if(cur.first+1 < row) q.push({cur.first+1,cur.second});
				if(cur.second-1 >= 0) q.push({cur.first,cur.second-1});
	
				map[cur.first][cur.second] = '#';
			}
		}
	}
	
	cout << ans << nn;
}

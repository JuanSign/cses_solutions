//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//coordinate
#define cord pair<int,int>

//N := number of rows
//M := number of columns
//bld[i][j] := the i-th row and j-th column of the building
//room := number of rooms

int N, M, room = 0;
vector<string> bld;

//check if a cell is valid
bool IsValid(cord x)
{
	if(x.first < 0 || x.first >= N) return false;
	if(x.second < 0 || x.second >= M) return false;
	if(bld[x.first][x.second] == '#') return false;
	return true;
}

//bfs function
void bfs(cord s)
{
	//create a bfs queue
	queue<cord> q;

	//insert source to queue
	q.push(s);
	//mark source as visited
	bld[s.first][s.second] = '#';

	//directions array	
	cord dir[] = {{-1,0},{0,1},{1,0},{0,-1}};
	
	//bfs
	while(!q.empty())
	{
		//current cell
		cord cC = q.front();
		q.pop();
		
		//check every neighbor of cC
		for(int i = 0; i < 4; i++)
		{	
			//new cell
			cord nC = {cC.first+dir[i].first,cC.second+dir[i].second};
			//only push valid cell to queue
			if(IsValid(nC))
			{
				//mark new cell as visited
				bld[nC.first][nC.second] = '#';
				//push new cell to queue
				q.push(nC);
			}
		}
	}	
}

int main()
{
	fastio()
	
	//input N and M
	cin >> N >> M;
	
	//resize building's map
	bld.resize(N);

	//input building
	for(int i = 0; i < N; i++) cin >> bld[i];
	
	//start bfs on every '.' cell
	for(int i = 0; i < N; i++)	
	{
		for(int j = 0; j < M; j++)
		{
			if(bld[i][j] == '.')
			{
				//increment count
				room++;
				//start bfs
				bfs({i,j});
			}
		}
	}
	
	//output count
	cout << room << nn;
}

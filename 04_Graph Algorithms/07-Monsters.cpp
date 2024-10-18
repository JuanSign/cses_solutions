//JuanSign
#include <bits/stdc++.h>
using namespace std;
 
#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
 
//coordinate
#define cord pair<int,int>
 
//N := the number of rows in the labyrinth
//M := the number of columns in the labyrinth
//laby[N][M] := 2D representation of the labyrinth
//utime[N][M] := the earliest time a cell become unvisited
//mons := vector of monster's coordinate
//A := starting coordinate
//B := ending coordinate
//par := map a coordinate to its parent
 
int N,M;
vector<string> laby;
vector<vector<int>> utime;
vector<cord> mons;
cord A,B;
map<cord,cord> par;
 
//checking functions
bool CheckCell(int i, int j, int timer)
{
	if(i < 0 || i >= N) return false;
	if(j < 0 || j >= M) return false;
	if(timer >= utime[i][j]) return false;
	return true;
}
 
//let the monsters walk first, and keep track of the time
void MonsterWalk()
{
	//create a bfs queue
	queue<pair<cord,int>> q;
	//load the monster into queue
	for(cord m : mons) q.push({m,0});
		
	//directions array
	int dX[] = {0,1,0,-1};
	int dY[] = {-1,0,1,0};
 
	//bfs
	while(!q.empty())
	{
		int cX = q.front().first.second;
		int cY = q.front().first.first;
		int timer = q.front().second;
		q.pop();
		if(timer >= utime[cY][cX]) continue;
		else utime[cY][cX] = timer;
		
		//check neighbor
		for(int i = 0; i < 4; i++)
		{
			int nX = cX+dX[i];
			int nY = cY+dY[i];
			if(CheckCell(nY,nX,timer+1)) 
			{	
				q.push({{nY,nX},timer+1});
			}
		}		
	}
}
 
bool IsBoundary(int i, int j)
{
	if(i == 0 || i == N-1) return true;
	if(j == 0 || j == M-1) return true;
	return false;
}
 
//player's walk
void PlayerWalk()
{
	//create a bfs queue
	queue<pair<cord,int>> q;
	//insert player
	q.push({A,0});
	//reset time in player's cell
	utime[A.first][A.second] = INT_MAX;
 
	//directions array
	int dX[] = {0,1,0,-1};
	int dY[] = {-1,0,1,0};
 
	//bfs
	while(!q.empty())
	{
		int cX = q.front().first.second;
		int cY = q.front().first.first;
		int timer = q.front().second;
		q.pop();
	
		if(timer >= utime[cY][cX]) continue;
		else utime[cY][cX] = timer;
		
		if(IsBoundary(cY,cX))
		{
			B = {cY,cX};	
			break;
		}		
		
		for(int i = 0; i < 4; i++)
		{
			int nX = cX+dX[i];
			int nY = cY+dY[i];
			if(CheckCell(nY,nX,timer+1))
			{
				q.push({{nY,nX},timer+1});
				par.insert({{nY,nX},{cY,cX}});
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
	laby.resize(N);
	utime.resize(N, vector<int>(M));
	
	//input labyrinth
	for(int i = 0; i < N; i++) cin >> laby[i];
	
	//reading the labyrinth
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(laby[i][j] == '.') utime[i][j] = INT_MAX;
			else if(laby[i][j] == '#') utime[i][j] = 0;
			else if(laby[i][j] == 'M')
			{
				mons.push_back({i,j});
				utime[i][j] = INT_MAX; //to be updated later
			}
			else 
			{
				A = {i,j};
				utime[i][j] = INT_MAX; //to be updated later
			}
		}
	}
 
	//edge case, A already on boundary
	if(IsBoundary(A.first, A.second))
	{
		cout << "YES" << nn;
		cout << 0 << nn;
		return 0;
	}
	
	//let the monsters walk
	MonsterWalk();
	//player walk
	PlayerWalk();
	
	if(par.find(B) != par.end())
	{
		cout << "YES" << nn;
		//generate path
		string path = "";
		
		cord cur = B;
		while(par.find(cur) != par.end())
		{
			cord prt = par[cur];
			if(cur.first > prt.first) path += 'D';
			else if(cur.first < prt.first) path += 'U';
			else 
			{
				if(cur.second > prt.second) path += 'R';
				else path += 'L';
			}
			cur = prt;
		}
	
		cout << path.size() << nn;
		for(int i = (int)path.size()-1; i >= 0; i--) cout << path[i];	
		cout << nn;
	}
	else cout << "NO" << nn;
 
	
}

//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//coordinate
#define cord pair<int,int>

//N := number of rows
//M := number of columns
//laby[i][j] := the i-th row and j-th column cell of the labyrinth
//par[cord] := parent of the coordinate <cord>
//A := coordinate of the starting position
//B := coordinate of the ending position

int N, M;
vector<string> laby;
map<cord,cord> par;
cord A, B;

//check cell
bool IsValid(cord x)
{
	if(x.first < 0 || x.first >= N) return false;
	if(x.second < 0 || x.second >= M) return false;
	if(laby[x.first][x.second] == '#') return false;
	return true;
}

//bfs
void bfs(cord s)
{
	//create a bfs queue
	queue<cord> q;
 
	//insert source to queue
	q.push(s);
	//mark source as visited
	laby[s.first][s.second] = '#';
 
	//directions array	
	cord dir[] = {{-1,0},{0,1},{1,0},{0,-1}};
	
	//bfs
	while(!q.empty())
	{
		//current cell
		cord cC = q.front();
		q.pop();
		
		//exit conditions
		if(cC == B) break;	
	
		//check every neighbor of cC
		for(int i = 0; i < 4; i++)
		{	
			//new cell
			cord nC = {cC.first+dir[i].first,cC.second+dir[i].second};
			//only push valid cell to queue
			if(IsValid(nC))
			{
				//mark new cell as visited
				laby[nC.first][nC.second] = '#';
				//assign parent
				par.insert({nC,cC});
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
	
	//resize labyrinth
	laby.resize(N);
	
	//input labyrinth
	for(int i = 0; i < N; i++) cin >> laby[i];
		
	//read labyrinth	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{	
			if(laby[i][j] == 'A') A = {i,j};
			if(laby[i][j] == 'B') B = {i,j};
		}
	}
	
	//start bfs from A
	bfs(A);
	
	//check if B has a parent
	if(par.find(B) != par.end())
	{
		//generate path
		string path = "";

		//current cell
		cord cC = B;
		//while current cell is not A
		while(cC != A)
		{
			//get parent
			cord pC = par[cC];	
			//determine directions
			if(cC.first > pC.first) path += 'D';
			else if(cC.first < pC.first) path += 'U';
			else
			{
				if(cC.second > pC.second) path += 'R';
				else path += 'L';
			}	
			//traverse
			cC = pC;
		}
	
		//output
		cout << "YES" << nn;
		cout << path.length() << nn;
		for(int i = (int)path.length()-1; i >= 0; i--) cout << path[i];
		cout << nn;
	}
	else cout << "NO" << nn;
}

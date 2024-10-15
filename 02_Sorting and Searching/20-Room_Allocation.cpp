//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input data
	int n; cin >> n;
	tuple<int,int,int> data[n];
	for(int i = 0; i < n; i++) 
	{
		cin >> get<0>(data[i]) >> get<1>(data[i]);
		get<2>(data[i]) = i;
	}
	sort(data, data+n);
		
	//priority queue to store the departure time of each room
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> room;
	
	int roomCount = 0;
	int ans[n];	
	
	//iterating
	for(int i = 0; i < n; i++)	
	{
		//if the earliest departure is greater than current arrival,
		if(room.empty() || room.top().first >= get<0>(data[i]))
		{
			//we increment roomCount and assign that room to the guest
			ans[get<2>(data[i])] = ++roomCount;
			//push to priority queue
			room.push({get<1>(data[i]), roomCount});
		}
		else
		{
			//we use the room for the new guest
			ans[get<2>(data[i])] = room.top().second;
			//remove old data
			room.pop();
			//push new data for the room to priority queue
			room.push({get<1>(data[i]), ans[get<2>(data[i])]});
		}
	}
	
	//output answer
	cout << roomCount << nn;
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << nn;
}

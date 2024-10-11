//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
		
	//input movies (end, start)
	int n; cin >> n;
	pair<int,int> movies[n];
	for(int i = 0; i < n; i++) cin >> movies[i].second >> movies[i].first;
	
	//sort based on ending time
	sort(movies, movies+n);	
	
	int ans = 0;
	int time = 0;
	for(int i = 0; i < n; i++) 
	{
		//if the starting time is >= current time
		//we watch that movie and update time to the movie's ending time
		if(movies[i].second >= time)
		{
			ans++;
			time = movies[i].first;
		}
	}
		
	cout << ans << nn;
}

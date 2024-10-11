//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n,x
	int n,x; cin >> n >> x;
		
	//input array {value, index}
	pair<int,int> data[n];
	for(int i = 0; i < n; i++)
	{
		cin >> data[i].first;
		data[i].second = i+1;
	}
	
	//if only one element, impossible
	if(n == 1)
	{
		cout << "IMPOSSIBLE" << nn;	
		return 0;
	}

	//sort the array
	sort(data, data+n);
	
	//keep adding the minimum and maximum
	int mini = 0;
	int maxi = n-1;
	while(mini < maxi)
	{	
		int sum = data[mini].first+data[maxi].first;
		if(sum==x)
		{
			cout << data[mini].second << " " << data[maxi].second << nn;
			break;
		}	
		else if(sum < x)
		{
			//increase the sum
			mini++;
		}
		else if(sum > x)
		{
			//decrease the sum
			maxi--;
		}
		
		if(mini >= maxi) cout << "IMPOSSIBLE" << nn;
	}
}

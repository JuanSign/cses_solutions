//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n, x
	int n, x; cin >> n >> x;	
	
	//input weight
	int data[n];
	for(int i = 0; i < n; i++) cin >> data[i];
	
	//sort the weight
	sort(data, data+n);
		
	int ans = 0;

	//pair the lightest available kid with the heaviest available kid (if possible)
	//if not possible, the heaviest kid will be place on a single gondola
	int light = 0;
	int heavy = n-1;
	
	while(light < heavy)
	{
		if(data[light]+data[heavy] <= x)
		{
			light++;
			heavy--;
		}
		else heavy--;
		if(light == heavy) ans++;
		ans++;
	}	
	
	cout << ans << nn;
}

//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input n
	int n; cin >> n;
		
	//input array
	int array[n];
	for(int i = 0; i < n; i++) cin >> array[i];
	
	long long ans = 0;
	//iterating array
	//if an element is smaller than the previous element,
	//increase that element to match the previous element.
	for(int i = 1; i < n; i++) 
	{
		if(array[i] < array[i-1])
		{
			ans += (array[i-1]-array[i]);
			array[i] = array[i-1];
		}
	}
	
	cout << ans << nn;
}

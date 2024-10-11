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
	int data[n]; 
	for(int i = 0; i < n; i++) cin >> data[i];
	
	//sort data
	sort(data, data+n);

	//find median
	int median = data[n/2];
	
	long long ans = 0;	

	//make every other stick the same as the median
	for(int i = n/2-1; i >= 0; i--) ans += (median-data[i]);
	for(int i = n/2+1; i < n; i++) ans += (data[i]-median);
	
	cout << ans << nn;
	
	
}

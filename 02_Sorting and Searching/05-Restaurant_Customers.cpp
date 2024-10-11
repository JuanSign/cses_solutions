//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//create 2 arrays of size n
	// one to store the arrival time, and one to store the leaving time
	int n; cin >> n;
	int A[n], L[n];
	for(int i = 0; i < n; i++) cin >> A[i] >> L[i];
	
	//sort both array
	sort(A, A+n);
	sort(L, L+n);
	
	int a = 0, l = 0;
	int cur = 0, ans = 0;
	while(a < n && l < n)
	{
		if(A[a] < L[l])
		{	
			cur++;
			ans = max(ans, cur);
			a++;
		}
		else
		{
			cur--;
			l++;
		}
	} 
		
	cout << ans << nn;
}

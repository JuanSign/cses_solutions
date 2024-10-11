//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	//input n, m, k
	int n, m, k; cin >> n >> m >> k;
	//input applicant's desired apartment size
	int A[n];
	for(int i = 0; i < n; i++) cin >> A[i];
	//input available apartments size
	int B[m];	
	for(int i = 0; i < m; i++) cin >> B[i];
	
	//sort both array increasingly
	sort(A, A+n);
	sort(B, B+m);	
	
	int ans = 0;
	int curApp = 0;
	int curApt = 0;
		
	//greedily pairing each applicant to the smallest available apartment
	while(curApp < n && curApt < m)
	{
		if(abs(A[curApp]-B[curApt]) <= k)
		{
			ans++;
			curApp++;
			curApt++;
		}
		else if(A[curApp] > B[curApt]) curApt++;
		else if(A[curApp] < B[curApt]) curApp++;
	}
	
	cout << ans << nn;
}

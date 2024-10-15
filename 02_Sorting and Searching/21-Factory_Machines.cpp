//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//function to check if the time x is enough
bool check(long long machine[], int N, int T, unsigned long long x)
{
	long long sum = 0;
	for(int i = 0; i < N; i++) sum += x/machine[i];
	if(sum >= T) return true;
	else return false;
}

int main()
{
	fastio()

	//input data
	int N;
	long long T;
	cin >> N >> T;
	long long machine[N];
	for(int i = 0; i < N; i++) cin >> machine[i];
	
	//define smallest value and highest value
	unsigned long long low = 1;
	unsigned long long high = T*(*(min_element(machine, machine+N)));
	
	//declare ans
	long long ans;	

	//do binary search to find optimal time
	while(low <= high)
	{
		unsigned long long mid = (low+high)/2;
		if(check(machine, N, T, mid))
		{
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	
	//output answer
	cout << ans << nn;
}

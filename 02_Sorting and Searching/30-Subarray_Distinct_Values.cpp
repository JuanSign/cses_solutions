//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
		
	//input data
	int n, k; cin >> n >> k;
	int data[n];
	for(int i = 0; i < n; i++) cin >> data[i];
	
	//start index of subarray
	int start = 0;
	//end index of subarray
	int end = 0;
	//number of distinct value in the subarray
	int dist = 0;
		
	//frequency map
	unordered_map<int,int> freq;
		
	long long ans = 0;	

	while(end < n)
	{
		//if current element didnt exist in the subarray
		// increment distinct count
		if(!freq[data[end]]) dist++;

		//update frequency map
		freq[data[end]]++;
	
		//while number of distinct value > k
		while(dist > k)
		{	
			//remove leftmost element
			freq[data[start]]--;
			//if leftmost element no longer exist in the subarray
			//decrement distinct count
			if(!freq[data[start]]) dist--;
			//increment starting index
			start++;
		}
		ans += (end-start+1);
		end++;
	}
	
	cout << ans << nn;
}

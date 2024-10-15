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
	
	//find median of each subarray
	//count the sum of low and hgh
	//the answer is 
	//  difference in left : median*(k-k/2-1) - sum of low
	//  difference in right : sum of high - median*(k/2)
	multiset<int> low;
	multiset<int> hgh;
	int Nlow = k-k/2;
	int Nhgh = k/2;
	long long sumLow = 0;
	long long sumHgh = 0;
	
	vector<int> firstK(k);
	for(int i = 0; i < k; i++) firstK[i] = data[i];
	sort(firstK.begin(), firstK.end());
	for(int i = 0; i < Nlow; i++) 	
	{
		low.insert(firstK[i]);
		sumLow += firstK[i];
	}
	for(int i = Nlow; i < k; i++) 
	{
		hgh.insert(firstK[i]);
		sumHgh += firstK[i];
	}
	
	//cost of the first k elements	
	cout << (*low.rbegin())*Nlow - sumLow + sumHgh - (*low.rbegin())*Nhgh << " ";
	
	for(int i = k; i < n; i++)
	{
		int ins = data[i];
		int rem = data[i-k];
		long long median = *low.rbegin();
	
		if(rem > median) 
		{
			hgh.erase(hgh.find(rem));
			sumHgh -= rem;
		}	
		else
		{
			low.erase(low.find(rem));
			sumLow -= rem;
		}
	
		if(ins > median)
		{
			hgh.insert(ins);
			sumHgh += ins;
		}
		else
		{
			low.insert(ins);
			sumLow += ins;
		}

		while(hgh.size() > Nhgh)
		{
			sumHgh -= *hgh.begin();
			sumLow += *hgh.begin();
			low.insert(*hgh.begin());
			hgh.erase(hgh.begin());
		}
		while(low.size() > Nlow)
		{
			sumLow -= *low.rbegin();
			sumHgh += *low.rbegin();
			hgh.insert(*low.rbegin());
			low.erase(--low.end());
		}

		median = *low.rbegin();
		cout << (median*(Nlow) - sumLow + sumHgh - median*(Nhgh)) << " ";
	}
}

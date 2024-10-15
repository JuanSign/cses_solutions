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
	
	//declare 2 multiset
	multiset<int> low; //store the k-floor(k/2) lowest element
	multiset<int> hgh; //store the floor(k/2) highest element

	//multiset size
	int Nlow = k-k/2;
	int Nhgh = k/2;
	
	//process the first K elements
	vector<int> firstK(k);
	for(int i = 0; i < k; i++) firstK[i] = data[i];
	sort(firstK.begin(), firstK.end());
	for(int i = 0; i < Nlow; i++) low.insert(firstK[i]);
	for(int i = Nlow; i < k; i++) hgh.insert(firstK[i]);
	
	//output the median of the first K elements
	cout << *low.rbegin() << " ";

	//process k...n-1
	for(int i = k; i < n; i++)
	{
		int ins = data[i];
		int rem = data[i-k];
		int median = *low.rbegin();
			
		if(rem > median) hgh.erase(hgh.find(rem));
		else low.erase(low.find(rem));
		
		if(ins > median) hgh.insert(ins);
		else low.insert(ins);

		while(hgh.size() > Nhgh)
		{
			low.insert(*hgh.begin());
			hgh.erase(hgh.begin());
		}
	
		while(low.size() > Nlow)
		{
			hgh.insert(*low.rbegin());
			low.erase(--low.end());
		}
		
		cout << *low.rbegin() << " ";
	}
	
}

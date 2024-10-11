//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input x,n
	int x,n; cin >> x >> n;
		
	//maintain 2 multiset
	//one to count all passage without traffic light	
	//one to count all traffic light positions
	multiset<int> traf;
	multiset<int> pass;
	//insert 0 and x to traf as a lower and upper bound
	traf.insert(0);
	traf.insert(x);	
	//insert x to pass (without any traffic light, the longest passage is x)
	pass.insert(x);
		
	int tr;
	while(n--)
	{
		cin >> tr;
		//since traffic lights position is unique upper_bound = lower_bound
		int nearestLeft = *(--traf.upper_bound(tr));
		int nearestRight = *(traf.upper_bound(tr));
		
		//remove the distance created by (nearestLeft)..(nearestRight)	
		auto it = pass.find(nearestRight-nearestLeft);
		pass.erase(it);	
	
		//insert new distance created by (nearestLeft)..(tr) and (tr)..(nearestRight)
		pass.insert(tr-nearestLeft);
		pass.insert(nearestRight-tr);
	
		//insert tr to traf
		traf.insert(tr);
	
		//output the maximum element in pass
		cout << *(--pass.end()) << " ";
	}
}

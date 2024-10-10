//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//solving for every a and b
void solve(int a, int b)
{	
	//let operation x : remove 1 from a and 2 from b
	//let operation y : remove 2 from a and 1 from b
	//let X : the number of times operation x is done
	//let Y : the number of times opearation y is done
	//if a and b can be emptied,
	//	a and b can be represented as
	//		a = X + 2Y
	//		b = 2X + Y
	// 	X = (2b-a)/3
	//	Y = (2a-b)/3
	//	therefore, 
	//		(2b-a) >= 0 and (2b-a)%3 == 0
	//		(2a-b) >= 0 and (2a-b)%3 == 0  
	
	if((2*b-a) < 0 || (2*a-b) < 0 || (2*b-a)%3 || (2*a-b)%3)
	{
		cout << "NO" << nn;
	}
	else cout << "YES" << nn;
}

int main()
{
	fastio()
	
	//input t
	int t; cin >> t;
		
	//input a and b
	int a,b;
	while(t--)
	{
		cin >> a >> b;
		solve(a,b);
	}
}

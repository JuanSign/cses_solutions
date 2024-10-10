//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//sequence pattern
	// 1 - first box
	// 2 3 4 - second L
	// 5 6 7 8 9 - third L
	// 10 11 12 13 14 15 16 - fourth L
	// ...
	// (n^2-2*(n-1)) (n^2-2*(n-1)+1) (n^2-2*(n-1)+2) ... n^2 - nth L
		
	//left-right down-up
	// 1
	// decreasing
	// increasing
	// ...
	//increasing for odd L and decreasing for even L
	
	//for every y,x
	// the number located in the (max(y,x))th L
	// if y > x
	//	its the xth leftmost number
	// if y < x
	// 	its the yth upmost number
	// if y = x
	//	its the xth leftmost number = yth upmost number
	
	//input t
	int t; cin >> t;
	
	//input y x
	while(t--)
	{
		int x, y; cin >> y >> x;
		long long n = max(x,y);
		if(y >= x)
		{
			if(n%2) cout << (n*n-2*(n-1)) + (x-1) << nn;
			else cout << (n*n) - (x-1) << nn;
		}
		else
		{
			if(n%2) cout << (n*n) - (y-1) << nn;
			else cout << (n*n-2*(n-1)) + (y-1) << nn;
		}
	}	

}

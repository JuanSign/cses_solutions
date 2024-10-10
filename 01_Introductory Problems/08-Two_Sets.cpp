//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//sum of 1+2+3+...+n is S = n(n+1)/2
	//in order to split S into 2 equal sum,
	//S must be divisible by 2
	
	//input n
	long long n; cin >> n;
	
	//check if n(n+1)/2 is divisible by 2
	if((n*(n+1)/2)%2==0)
	{
		cout << "YES" << nn;
		//greedy approach
		//	we want each set to have the sum of S/2
		//	we keep adding the largest available element to set A
		//	when S/2-(sum of A) is <= the next largest available element
		//  we add (S/2-(sum of A)) to set A, and the rest to set B
	
		bool taken[n+1] = {false};
		long long target = (n*(n+1))/4;
		vector<int> A,B;
		for(int i = n; i > 0; i--)
		{
			A.push_back(i);
			taken[i] = true;
			
			target -= i;
			if(target <= i-1)
			{
				//only add to A if target is not zero
				if(target)
				{
					A.push_back(target);
					taken[target] = true;
				}
				break;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			if(!taken[i]) B.push_back(i);
		}
		
		//A
		cout << A.size() << nn;
		for(int i : A) cout << i << " ";
		cout << nn;	
		//B
		cout << B.size() << nn;
		for(int i : B) cout << i << " ";
		cout << nn;
	}
	else cout << "NO" << nn;
}
	

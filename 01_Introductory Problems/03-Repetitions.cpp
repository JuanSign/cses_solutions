//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input string
	string s; cin >> s;
	
	//last character
	char last = 'm'; //random
	
	//longest and current length
	int longest = INT_MIN;
	int current = 1;
	
	//iterating string
	for(char i : s)
	{
		if(i == last) current++;
		else
		{
			last = i;
			current = 1;
		}
		longest = max(longest, current);
	}
	
	cout << longest << nn;
}

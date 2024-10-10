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
	
	//count for each alphabet
	int count[26] = {0};
	
	//iterating the string while counting appearance for each alphabet
	for(char i : s) count[i-'A']++;
	
	//counting how many alphabet that appears odd number of times
	int odd = 0;
	for(int i = 0; i < 26; i++) odd += (count[i]%2);
	
	//if odd > 1, we cant create a palindrome
	if(odd > 1) cout << "NO SOLUTION" << nn;
	else
	{	
		//left half = right half
		string half = "";
		//middle (if exist)
		string mid = "";
		for(int i = 0; i < 26; i++)
		{
			if(count[i]%2) for(int j = 0; j < count[i]; j++) mid += char(i+65);
			else for(int j = 0; j < count[i]/2; j++) half += char(i+65);
		}
		
		//output
		for(int i = 0; i < half.size(); i++) cout << half[i];
		for(int i = 0; i < mid.size(); i++) cout << mid[i];
		for(int i = half.size()-1; i >= 0; i--) cout << half[i];
		cout << nn;
	}
}

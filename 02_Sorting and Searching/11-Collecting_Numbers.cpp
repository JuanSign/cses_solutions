//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()	
	
	//input data 
	//while maintaining position array for each element
	int n; cin >> n;
	int positions[n+1];
		
	int number;
	for(int i = 1; i <= n; i++)
	{
		cin >> number;
		positions[number] = i;
	}
	
	int round = 1;
	//for every adjacent element with positions[i+1] < positions[i],	
	//we have to do another round
	for(int i = 1; i < n; i++) round += (positions[i] > positions[i+1]);
	
	cout << round << nn;
}

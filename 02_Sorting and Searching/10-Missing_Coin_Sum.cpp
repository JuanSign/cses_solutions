//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fastio()
	
	//input data
	int n; cin >> n;	
	int data[n];
	for(int i = 0; i < n; i++) cin >> data[i];
	
	//sort the data
	sort(data, data+n);
		
	//X is the smallest value we cant get
	long long X = 1;
	int i = 0; //current coin to process	

	//if the next smallest coin is greater than X, the answer is X
	while(i < n && data[i] <= X) X += data[i++];

	cout << X << nn;
}

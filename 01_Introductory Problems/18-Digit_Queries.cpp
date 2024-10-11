//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//a^b
long long power(long long a, long long b)
{
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a);
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

//solve
int solve(long long k)
{
	//k will point to a part of an integer X
	//get the length of integer X
	int digit = 1;
	long long base = 9;
	while(k - (digit*base) > 0)
	{
		k -= digit*base;
		digit++;
		base *= 10;
	}	
	
	//get the number X
	long long X = power(10, (digit - 1)) + (k - 1) / digit;
	
	//check where k is pointing to
	if((k%digit) != 0) X /= power(10, (digit-(k%digit)));
	
	return X%10;	
}

int main()
{
	fastio()
	
	//input q
	int q; cin >> q;
	
	while(q--)
	{
		//input k
		long long k; cin >> k;	
		//solve
		cout << solve(k) << nn;
	}
}

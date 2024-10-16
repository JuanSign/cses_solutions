//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

void build(long long segTree[], int arr[], int i, int l, int r)
{
	if(l == r) segTree[i] = arr[l];
	else
	{
		int mid = (l+r)/2;
		build(segTree, arr, 2*i+1, l, mid);
		build(segTree, arr, 2*i+2, mid+1, r);
		segTree[i] = min(segTree[2*i+1],segTree[2*i+2]);
	}
}

long long getMin(long long segTree[], int i, int lb, int rb, int l, int r)
{
	if(lb==l && rb==r) return segTree[i];
	if(l > r) return LONG_LONG_MAX;
	int mid = (lb+rb)/2;
	return min(getMin(segTree, 2*i+1, lb, mid, l, min(mid,r)),getMin(segTree, 2*i+2, mid+1, rb, max(mid+1,l), r));
}
int main()
{
	fastio()
		
	//basic segment tree	
	
	//input data
	int n,q; cin >> n >> q;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	//build segTree
	long long segTree[4*n];
	build(segTree, arr, 0, 0, n-1);

	//process queries
	while(q--)
	{
		int l, r; cin >> l >> r;	
		cout << getMin(segTree, 0, 0, n-1, l-1, r-1) << nn;
	}
	
}

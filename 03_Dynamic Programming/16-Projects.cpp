//JuanSign
#include <bits/stdc++.h>
using namespace std;

#define nn '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

//struct for object
struct project
{
	int ai, bi, value;
		
	//for sorting based on ending time
	bool operator<(const project &other) const{
		return bi < other.bi;
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	//input data
	int n; 
	cin >> n;
	vector<project> p(n);
	for(int i = 0; i < n; i++) cin >> p[i].ai >> p[i].bi >> p[i].value;
	
	//sort projects based on its ending times
	sort(p.begin(),p.end());

	//{ending time, maximum reward}
	set<pair<int, long long>> ends;
	ends.insert({0,0});
	
	long long answer = 0;
	
	for(int i = 0; i < n; i++)
	{
		//find the project that we can do before we do current project
		auto t = ends.lower_bound({p[i].ai, -1});	
		t--;
		//try to update the answer
		answer = max(answer, p[i].value + t->second);
		//update set to tell that if we start at p[i].bi+1, we can get (answer) reward
		ends.insert({p[i].bi, answer});
	}
	
	//output
	cout << answer << nn;
}

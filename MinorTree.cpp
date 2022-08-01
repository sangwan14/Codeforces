#include <bits/stdc++.h>
using namespace std;

class DSU{
	vector<int>par;
	vector<int>rank;

	public:

	DSU(int n)
	{
		for(int i = 0; i <= n ; i++)
		{
			par.push_back(i);
			rank.push_back(0);
		}
	}

	int findPar(int node)
	{
		if(node == par[node])
			return node;

		int leader = findPar(par[node]);
		par[node] = leader;

		return leader;
	}

	void unionn(int a , int b)
	{
		a = findPar(a);
		b = findPar(b);

		if(rank[a] > rank[b])
			swap(a , b);

		par[a] = b;

		if(rank[a] == rank[b])
			rank[b]++;
	}
};



void solve()
{
	int n , m;
	cin >> n >> m;

	vector<pair<pair<int,int> , int>>edges;

	for(int i = 0 ; i < m ; i++)
	{
		int a , b , c;
		cin >> a >> b >> c;
		edges.push_back({{a , b} , c});
	}

	int ans = -1;

	for(int bit = 31 ; bit >= 0 ; bit--)
	{
		// do we have to take it ?

		DSU d(n);
		int cnt = 0;
        ans &= ~(1<<bit);
        
		for(auto x : edges)
		{
			int c = x.second;
			int a = x.first.first , b = x.first.second;
			
			int orr = ans | c;

			if(orr != ans)
				continue;

			if(d.findPar(a) == d.findPar(b))
				continue;

			cnt++;
			d.unionn(a , b);
		}

		if(cnt < n - 1)
			ans ^= (1 << bit);
	}

	cout << ans << endl;
}
int32_t main()
{
	FAST;
	int t = 1;
	cin >> t;
	/*
	fact[0] = 1;
	for(int i = 1;i<M;i++)
		fact[i] = (i * fact[i-1])%mod;
		*/
	int test = 1;
	while(t--)
	{
	//	cout << "Case #" << test << ": ";
		solve();
		test++;
	}
} 

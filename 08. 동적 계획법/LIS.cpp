#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;
const int INF = 1e9;

vector<int> v;
vector<vector<pii>> dp;

pii GetLIS(int st, int en)
{
	if(dp[st][en].first > 0)
		return dp[st][en];
	if(st == en)
		return dp[st][en] = {1, v[en]};
	
	pii ret = {1, v[en]};
	for(int i=st; i<en; ++i)
	{
		pii cur = GetLIS(st, i);
		
		if(cur.second >= v[en])
			continue;
		if(cur.first+1 > ret.first)
			ret = {cur.first+1, v[en]};
	}

	return dp[st][en] = ret;
}

void Solve()
{
	int N;
	cin >> N;

	v.clear();
	v.resize(N);
	for(auto& elem : v)
		cin >> elem;

	dp.clear();
	dp.resize(N, vector<pii>(N, {0, INF}));

	int ans = 0;
	for(int i=0; i<N; ++i)
		ans = max(ans, GetLIS(0, i).first);
	cout << ans << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
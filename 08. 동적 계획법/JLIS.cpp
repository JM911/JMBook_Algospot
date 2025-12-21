#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll INF = 1e13;

int n, m;
vector<ll> A, B;
vector<vector<int>> dp;

int GetJLIS(int idxA, int idxB)
{
	// if(idxA>n || idxB>m) return 0;
	int& ret = dp[idxA][idxB];
	if(ret > 0) return ret;

	ret = 2;

	ll curNum = max(A[idxA], B[idxB]);
	for(int i=idxA+1; i<=n; ++i)
		if(A[i] > curNum) ret = max(ret, GetJLIS(i, idxB)+1);
	for(int i=idxB+1; i<=m; ++i)
		if(B[i] > curNum) ret = max(ret, GetJLIS(idxA, i)+1);

	return ret;
}

void Solve()
{
	cin >> n >> m;

	A.clear(); A.resize(n+1, -INF);
	B.clear(); B.resize(m+1, -INF);

	for(int i=1; i<=n; ++i)
		cin >> A[i];
	for(int i=1; i<=m; ++i)
		cin >> B[i];
	
	dp.clear(); dp.resize(n+1, vector<int>(m+1, 0));

	cout << GetJLIS(0, 0) - 2 << '\n';
}

int main()
{
	FASTIO;

	int c;
	cin >> c;
	while(c--)
		Solve();
}
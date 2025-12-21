#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> dp;

int GetMax(int i, int j)
{
	if(i<0 || j<0 || i>=n || j>=n)
		return 0;

	int& ret = dp[i][j];
	if(ret > 0)
		return ret;

	ret = max(ret, GetMax(i+1, j)+board[i][j]);
	ret = max(ret, GetMax(i+1, j+1)+board[i][j]);
	return ret;
}

void Solve()
{
	cin >> n;

	board.clear();
	board.resize(n, vector<int>(n));
	for(int i=0; i<n; ++i)
		for(int j=0; j<=i; ++j)
			cin >> board[i][j];
	
	dp.clear();
	dp.resize(n, vector<int>(n, 0));

	// int ans = 0;
	// for(int i=0; i<n; ++i)
	// 	ans = max(ans, GetMax(n-1, i));
	cout << GetMax(0, 0) << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int n, m;
bool bFriend[10][10];
bool vis[10];
int Fact[6] = { 1, 1, 2, 6, 24, 120 };

int GetAns(int left)
{
	if(left <= 0) return 1;

	int ret = 0;

	for(int i=0; i<n; ++i)
	{
		if(vis[i]) continue;
		vis[i] = true;

		for(int j=i+1; j<n; ++j)
		{
			if(vis[j] || !bFriend[i][j]) continue;
			vis[j] = true;
			ret += GetAns(left-2);
			vis[j] = false;
		}
		vis[i] = false;
	}

	return ret;
}

void Solve()
{
	fill(&bFriend[0][0], &bFriend[9][10], false);
	fill(&vis[0], &vis[10], false);

	cin >> n >> m;
	
	while(m--)
	{
		int a, b;
		cin >> a >> b;

		bFriend[a][b] = true;
		bFriend[b][a] = true;
	}

	cout << GetAns(n) / Fact[n/2] << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
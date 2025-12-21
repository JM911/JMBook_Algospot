#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

void Solve()
{
	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));
	for(auto& row : board)
		for(auto& elem : row)
			cin >> elem;
	
	set<pii> mySet[101][101];
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			for(int d=0; d<2; ++d)
			{
				int x = i + dx[d] * board[i][j];
				int y = j + dy[d] * board[i][j];
				if(x<0 || y<0 || x>=n || y>=n) continue;
				
				mySet[x][y].insert({i, j});
			}
		}
	}

	vector<vector<bool>> vis(n, vector<bool>(n, false));
	queue<pii> q;
	q.push({n-1, n-1});
	vis[n-1][n-1] = true;
	
	while(!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if(curX == 0 && curY == 0)
		{
			cout << "YES\n";
			return;
		}

		for(auto elem : mySet[curX][curY])
		{
			if(vis[elem.first][elem.second]) continue;

			vis[elem.first][elem.second] = true;
			q.push(elem);
		}
	}

	cout << "NO\n";
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
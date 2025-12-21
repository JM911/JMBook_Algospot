#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int H, W;
vector<vector<char>> board;
const int dx[4][2] = {{0, 1}, {1, 1}, {1, 1}, {0, 1}};
const int dy[4][2] = {{1, 1}, {0, 1}, {0, -1}, {1, 0}};

int GetAns(int lastX, int lastY, int leftWhite)
{
	if(leftWhite <= 0)
		return 1;	

	int ret = 0;

	bool bCheck = false;
	for(int i=lastX; i<H; ++i)
	{
		for(int j=0; j<W; ++j)
		{
			if(i == lastX && j <= lastY) continue;

			if(board[i][j] != '.') continue;
			bCheck = true;
			board[i][j] = 'f';

			for(int d=0; d<4; ++d)
			{
				int x1 = i + dx[d][0];
				int y1 = j + dy[d][0];
				int x2 = i + dx[d][1];
				int y2 = j + dy[d][1];

				if(x1<0 || y1<0 || x1>=H || y1>=W) continue;
				if(x2<0 || y2<0 || x2>=H || y2>=W) continue;
				if(board[x1][y1] != '.' || board[x2][y2] != '.') continue;

				board[x1][y1] = 'f';
				board[x2][y2] = 'f';
				ret += GetAns(i, j, leftWhite-3);
				board[x1][y1] = '.';
				board[x2][y2] = '.';
			}
			board[i][j] = '.';

			break;
		}
		if(bCheck) break;
	}

	return ret;
}

void Solve()
{
	cin >> H >> W;
	
	board.clear();
	board.resize(H, vector<char>(W));
	
	int totalWhite = 0;
	for(int i=0; i<H; ++i)
	{
		string s;
		cin >> s;
		for(int j=0; j<W; ++j)
		{
			board[i][j] = s[j];
			if(s[j] == '.') ++totalWhite;
		}
	}

	cout << GetAns(0, -1, totalWhite) << '\n';
	int a =0;
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
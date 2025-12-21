#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;

char board[5][5];
string target;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

unordered_set<int> prevPos, curPos;

bool hasWord(int idx)
{
	if(idx>=target.size())
		return true;
	
	curPos.clear();
	for(auto elem : prevPos)
	{
		int curX = elem / 10;
		int curY = elem % 10;

		for(int d=0; d<8; ++d)
		{
			int x = curX + dx[d];
			int y = curY + dy[d];
			if(x<0 || y<0 || x>=5 || y>=5) continue;
			if(board[x][y] != target[idx]) continue;

			curPos.insert(x*10 + y);
		}
	}

	if(curPos.empty()) return false;
	
	prevPos.clear();
	for(auto elem : curPos)
		prevPos.insert(elem);
	return hasWord(idx+1);
}

void Solve()
{
	for(int i=0; i<5; ++i)
	{
		string s;
		cin >> s;
		for(int j=0; j<5; ++j)
			board[i][j] = s[j];
	}

	int N;
	cin >> N;
	while(N--)
	{
		cin >> target;

		prevPos.clear();
		prevPos.insert(11);
		prevPos.insert(12);
		prevPos.insert(13);
		prevPos.insert(31);
		prevPos.insert(32);
		prevPos.insert(33);
		
		cout << target << ' ' << (hasWord(0) ? "YES" : "NO") << '\n';
	}
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
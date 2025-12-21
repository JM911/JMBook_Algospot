#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9;
int myClock[16];
vector<vector<int>> buttons = {{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7},
								{6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15},
								{1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};
int ans = INF;

bool MyCheck()
{
	for(int i=0; i<16; ++i)
		if(myClock[i] > 0) return false;
	return true;
}

void CalcAns(int lastButton, int lastCount)
{
	if(lastButton >= 9) return;

	int curButton = lastButton + 1;
	int curCount = lastCount;
	for(int i=0; i<4; ++i)
	{
		if(MyCheck()) ans = min(ans, curCount);
		CalcAns(curButton, curCount);

		if(i==4) break;
		for(auto elem : buttons[curButton])
		{
			myClock[elem] += 3;
			myClock[elem] %= 12;
		}
		++curCount;
	}
}

void Solve()
{
	ans = INF;
	for(int i=0; i<16; ++i)
	{
		cin >> myClock[i];
		myClock[i] %= 12;
	}

	CalcAns(-1, 0);
	cout << (ans==INF ? -1 : ans) << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
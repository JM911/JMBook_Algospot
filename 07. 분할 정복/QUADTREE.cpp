#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

string s;

string Rearrange(int curIdx)
{
	if(s[curIdx] != 'x')
		return s.substr(curIdx, 1);
	
	int curLen = 1;
	int nextIdx = curIdx + 1;
	
	string part[4];
	for(int i=0; i<4; ++i)
	{
		part[i] = Rearrange(nextIdx);
		nextIdx += part[i].size();
	}

	return "x" + part[2] + part[3] + part[0] + part[1];
}

void Solve()
{
	cin >> s;
	cout << Rearrange(0) << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
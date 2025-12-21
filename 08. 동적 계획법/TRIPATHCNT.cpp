#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;

int n;
int tri[105][105];
pii ans[105][105];

pii GetAns(int r, int c) {
	if(r<0 || r>=n || c>r) return {0, 0};
	pii& ret = ans[r][c];
	if(ret.first > 0) return ret;

	if(r == n-1) {
		ret.first = tri[r][c];
		ret.second = 1;
		return ret;
	}

	for(int i=0; i<=1; ++i) {
		pii bel = GetAns(r+1, c+i);
		if(bel.first > ret.first)
			ret = bel;
		else if(bel.first == ret.first)
			ret.second += bel.second;
	}

	ret.first += tri[r][c];
	return ret;
}

void Solve() {
	cin >> n;
	
	for(int i=0; i<105; ++i)
		for(int j=0; j<105; ++j) {
			tri[i][j] = 0;
			ans[i][j] = {0, 0};
		}

	for(int i=0; i<n; ++i)
		for(int j=0; j<=i; ++j)
			cin >> tri[i][j];
	
	pii curAns = GetAns(0, 0);
	cout << curAns.second << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int MOD = 1000000007;
int dp[105];

int GetAns(int n) {
	int& ret = dp[n];

	if(ret < 0) {
		ret = GetAns(n-1) + GetAns(n-2);
		ret %= MOD;
	}

	return ret;
}

int main()
{
	FASTIO;

	fill(&dp[0], &dp[105], -1);
	dp[0] = 1;
	dp[1] = 1;

	int C;
	cin >> C;

	while(C--) {
		int n;
		cin >> n;
		cout << GetAns(n) << '\n';
	}
}
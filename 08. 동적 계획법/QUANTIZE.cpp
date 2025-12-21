#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9;
int N, S;
vector<int> v, ps;
vector<vector<int>> dp;
vector<vector<vector<int>>> dpAns;

void InitPS()
{
	ps.clear();
	ps.resize(N+1, 0);

	for(int i=1; i<=N; ++i)
		ps[i] = ps[i-1] + v[i-1];
}

int GetMin(int startIdx, int endIdx)
{
	int& ret = dp[startIdx][endIdx];
	if(ret != INF) return ret;

	int num = endIdx - startIdx;
	int sum = ps[endIdx] - ps[startIdx];
	int q = sum / num;
	int r = sum % num;

	if(r*2 >= num)
		++q;

	ret = 0;
	for(int i=startIdx; i<endIdx; ++i)
		ret += (v[i]-q) * (v[i]-q);
	return ret;
}

int GetAns(int startIdx, int endIdx, int len)
{
	// if(len == S)
	// 	return INF;

	int& ret = dpAns[startIdx][endIdx][len];
	if(ret != INF)
		return ret;

	/*int*/ ret = GetMin(startIdx, endIdx);

	if(len < S-1)
		for(int i=startIdx+1; i<endIdx; ++i)
			ret = min(ret, GetMin(startIdx, i) + GetAns(i, endIdx, len+1));

	return ret;
}

void Solve()
{
	cin >> N >> S;

	v.clear();
	v.resize(N);
	for(auto& elem : v)
		cin >> elem;
	
	sort(v.begin(), v.end());
	InitPS();
	
	dp.clear();
	dp.resize(N+1, vector<int>(N+1, INF));
	dpAns.clear();
	dpAns.resize(N+1, vector<vector<int>>(N+1, vector<int>(12, INF)));

	cout << GetAns(0, N, 0) << '\n';
	int a=0;
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
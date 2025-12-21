#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int pan[20010];

int GetMax(int startIdx, int endIdx)
{
	if(endIdx - startIdx == 1)
		return pan[startIdx];
	
	int halfLen = (endIdx - startIdx)/2;
	int leftMax = GetMax(startIdx, startIdx + halfLen);
	int rightMax = GetMax(startIdx + halfLen, endIdx);

	int l = startIdx + halfLen - 1;
	int r = startIdx + halfLen;
	int curHeight = min(pan[l--], pan[r++]);
	int curWidth = 2;
	int ret = curHeight * curWidth;

	while(l>=startIdx && r<endIdx)
	{
		if(pan[l] > pan[r])
			curHeight = min(curHeight, pan[l--]);
		else
			curHeight = min(curHeight, pan[r++]);

		++curWidth;
		ret = max(ret, curHeight * curWidth);
	}

	while(l>=startIdx)
	{
		curHeight = min(curHeight, pan[l--]);
		++curWidth;
		ret = max(ret, curHeight * curWidth);
	}

	while(r<endIdx)
	{
		curHeight = min(curHeight, pan[r++]);
		++curWidth;
		ret = max(ret, curHeight * curWidth);
	}

	return max({leftMax, rightMax, ret});
}

void Solve()
{
	int N;
	cin >> N;

	for(int i=0; i<N; ++i)
		cin >> pan[i];
	
	cout << GetMax(0, N) << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
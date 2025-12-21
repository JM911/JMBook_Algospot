#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int GetSubLevel(const string& s)
{
	if(s.size() < 3 || s.size() > 5) return 999;

	char firstChar = s[0];
	int len = s.size();
	
	bool bCheck = true;
	for(int i=1; i<len; ++i)
	{
		if(s[i] != firstChar)
		{
			bCheck = false;
			break;
		}
	}
	if(bCheck) return 1;

	bCheck = true;
	for(int i=1; i<len; ++i)
	{
		if((int)s[i]-(int)s[i-1] != 1)
		{
			bCheck = false;
			break;
		}
	}
	if(bCheck) return 2;

	bCheck = true;
	for(int i=1; i<len; ++i)
	{
		if((int)s[i]-(int)s[i-1] != -1)
		{
			bCheck = false;
			break;
		}
	}
	if(bCheck) return 2;

	bCheck = true;
	char secondChar = s[1];
	for(int i=2; i<len; ++i)
	{
		if(i%2==0)
		{
			if(s[i]!=firstChar)
			{
				bCheck = false;
				break;
			}
		}
		else
		{
			if(s[i]!=secondChar)
			{
				bCheck = false;
				break;
			}
		}
	}
	if(bCheck) return 4;

	bCheck = true;
	int d = (int)secondChar - (int)firstChar;
	for(int i=2; i<len; ++i)
	{
		if((int)s[i] - (int)s[i-1] != d)
		{
			bCheck = false;
			break;
		}
	}

	if(bCheck) return 5;
	
	return 10;
}

const int INF = 40000;
vector<int> dp;
string target;

int GetLevel(int idx)
{
	if(idx>=target.size()) return 0;
	int& ret = dp[idx];
	if(ret < INF) return ret;

	int last = min(5, (int)target.size()-idx+1);
	
	for(int i=3; i<=last; ++i)
		ret = min(ret, GetSubLevel(target.substr(idx, i)) + GetLevel(idx+i));

	return ret;
}

void Solve()
{
	cin >> target;

	dp.clear();
	dp.resize(target.size(), INF);
	cout << GetLevel(0) << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

bool canBe(const string& W, const string& target, int idxW, int idxT)
{
	if(idxW >= W.size() && idxT >= target.size())
		return true;
	
	if(idxT >= target.size() && W[idxW] == '*')
	{
		if(idxW == W.size()-1)
			return true;
		else
			return canBe(W, target, idxW+1, idxT);
	}
	
	if(idxW >= W.size() || idxT >= target.size())
		return false;
	
	if(W[idxW] == '*')
	{
		if(canBe(W, target, idxW+1, idxT))
			return true;
		if(canBe(W, target, idxW, idxT+1))
			return true;
		return false;
	}

	if(W[idxW] == target[idxT] || W[idxW] == '?')
		return canBe(W, target, idxW+1, idxT+1);
	return false;
}

void Solve()
{
	string W;
	cin >> W;

	int N;
	cin >> N;

	set<string> s;
	while(N--)
	{
		string str;
		cin >> str;
		s.insert(str);
	}

	for(auto elem : s)
	{
		if(canBe(W, elem, 0, 0))
			cout << elem << '\n';
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
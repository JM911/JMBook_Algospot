#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int K = 200;

void MyAdd(vector<int>& a, const vector<int>& b, int k)
{
	for(int i=0; i<k; ++i)
		if(i >= a.size()) a.push_back(0);
	for(int i=0; i<b.size(); ++i)
	{
		if(i+k<a.size()) a[i+k] += b[i];
		else a.push_back(b[i]);
	}
}

void MySubtract(vector<int>& a, const vector<int>& b)
{
	for(int i=0; i<b.size(); ++i)
	{
		if(i<a.size()) a[i] -= b[i];
		else a.push_back(-b[i]);
	}
}

vector<int> MyMultiply(const vector<int>& a, const vector<int>& b)
{
	int lenA = a.size();
	int lenB = b.size();
	if(lenA < lenB) return MyMultiply(b, a);

	if(lenB == 0) return vector<int>();

	if(lenA < K)
	{
		vector<int> ret(lenA+lenB-1, 0);
		for(int i=0; i<lenA; ++i)
		{
			for(int j=0; j<lenB; ++j)
			{
				ret[i+j] += a[i]*b[j];
			}
		}
		return ret;
	}

	int half = lenA / 2;
	vector<int> a0(a.begin(), a.begin()+half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin()+min((int)b.size(), half));
	vector<int> b1(b.begin()+min((int)b.size(), half), b.end());

	vector<int> z2 = MyMultiply(a1, b1);
	vector<int> z0 = MyMultiply(a0, b0);
	
	MyAdd(a0, a1, 0);
	MyAdd(b0, b1, 0);
	vector<int> z1 = MyMultiply(a0, b0);
	MySubtract(z1, z0);
	MySubtract(z1, z2);

	vector<int> ret;
	MyAdd(ret, z0, 0);
	MyAdd(ret, z1, half);
	MyAdd(ret, z2, half*2);
	
	return ret;
}

void Solve()
{
	string idol, fan;
	cin >> idol >> fan;

	int idolLen = idol.size();
	int fanLen = fan.size();

	vector<int> idolV(idolLen);
	vector<int> fanV(fanLen);


	for(int i=0; i<idolLen; ++i)
		idolV[i] = (idol[i] == 'M' ? 1 : 0);
	for(int i=0; i<fanLen; ++i)
		fanV[i] = (fan[fanLen-i-1] == 'M' ? 1 : 0);
	
	vector<int> ansV = MyMultiply(idolV, fanV);

	int ans = 0;
	for(int i=idolLen-1; i<fanLen; ++i)
		if(ansV[i] == 0) ++ans;
	cout << ans << '\n';
}

int main()
{
	FASTIO;

	int C;
	cin >> C;
	while(C--)
		Solve();
}
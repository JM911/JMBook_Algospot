#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int C;

int main()
{
	FASTIO;

	cout.precision(8);
	cout << fixed;

	cin >> C;
	while(C--)
	{
		int N, L;
		cin >> N >> L;

		vector<int> v, ps;
		v.resize(N);
		for(auto& e : v)
			cin >> e;

		ps.resize(N+1);
		ps[0] = 0;
		for(int i=0; i<N; i++)
			ps[i+1] = ps[i] + v[i];
		
		double ans = 200.0;
		for(int i=0; i<=N; i++)
			for(int j=i+L; j<=N; j++)
				ans = min(ans, (double)(ps[j] - ps[i]) / (double)(j - i));

		cout << ans << '\n';
	}
}
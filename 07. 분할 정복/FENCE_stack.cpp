#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

void Solve()
{
  int N;
  cin >> N;

  vector<int> h(N+2, 0);
  vector<int> l(N+2, 0), r(N+2, N+1);

  for(int i=1; i<=N; ++i)
    cin >> h[i];

  stack<pair<int, int>> s;
  s.push({0, 0});

  for(int i=1; i<=N; ++i)
  {
    while(!s.empty() && s.top().second > h[i])
    {
      r[s.top().first] = i;
      s.pop();
    }

    if(s.top().second == h[i])
    {
      l[i] = l[s.top().first];
      s.push({i, h[i]});
    }
    else
    {
      l[i] = s.top().first;
      s.push({i, h[i]});
    }
  }

  int ans = 0;
  for(int i=1; i<=N; ++i)
    ans = max(ans, h[i] * (r[i] - l[i] - 1));
  
  cout << ans << "\n";
}

int main()
{
  FASTIO;

  int C;
  cin >> C;

  while(C--)
    Solve();
}
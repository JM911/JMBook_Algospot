#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

void Solve()
{
  int N, K;
  cin >> N >> K;

  vector<int> pre(N+1), nxt(N+1);
  for(int i=1; i<=N; ++i)
  {
    pre[i] = (i-2+N) % N + 1;
    nxt[i] = (i) % N + 1;
  }

  int cnt = 0;
  int cur = 1;
  
  while(cnt++ < N-2)
  {
    int cache = cur;
    
    nxt[pre[cache]] = nxt[cache];
    pre[nxt[cache]] = pre[cache];
    
    for(int i=0; i<K; ++i)
      cur = nxt[cur];

    // DEBUG
    // nxt[cache] = -1;
    // pre[cache] = -1;
  }

  int a = cur;
  int b = nxt[cur];
  cout << min(a, b) << " " << max(a, b) << "\n";
}

int main()
{
  FASTIO;

  int C;
  cin >> C;
  while(C--)
    Solve();
}
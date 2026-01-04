#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll MOD = 20090711;

void solve()
{
  int N;
  ll a, b;
  cin >> N >> a >> b;

  priority_queue<ll> pql;
  priority_queue<ll, vector<ll>, greater<ll>> pqr;

  ll A = 1983LL;
  ll ans = 0LL;

  if(N >= 1)
  {
    pql.push(A);
    ans += pql.top();
    A = (A * a + b) % MOD;
  }

  if(N >= 2)
  {
    if(A < pql.top())
    {
      pql.push(A);
      pqr.push(pql.top());
      pql.pop();
    }
    else
    {
      pqr.push(A);
    }

    ans += pql.top();
    A = (A * a + b) % MOD;
  }

  for(int i=2; i<N; ++i)
  {
    ll lt = pql.top();
    ll rt = pqr.top();

    if(A < lt)
    {
      pql.push(A);
      if(pql.size() - pqr.size() >= 2)
      {
        pqr.push(pql.top());
        pql.pop();
      }
    }
    else
    {
      pqr.push(A);
      if(pqr.size() > pql.size())
      {
        pql.push(pqr.top());
        pqr.pop();
      }
    }

    ans += pql.top();
    ans %= MOD;
    A = (A * a + b) % MOD;
  }

  cout << ans << "\n";
}

int main()
{
  FASTIO;

  int C;
  cin >> C;
  while(C--)
    solve();
}
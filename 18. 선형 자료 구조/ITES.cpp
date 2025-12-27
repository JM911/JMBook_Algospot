#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll MOD = (ll)1 << 32;

void Solve()
{
  int K, N;
  cin >> K >> N;

  queue<ll> q;
  ll sum = 0;
  ll curA = 1983;
  ll curSig = curA % 10000 + 1;

  ll ans = 0;
  int i = 0;
  
  while(i <= N)
  {
    while(i <= N && sum < K)
    {
      sum += curSig;
      q.push(curSig);
      curA = (curA * 214013 + 2531011) % MOD;
      curSig = curA % 10000 + 1;
      ++i;
    }

    while(sum >= K)
    {
      if(sum == K)
        ++ans;
      
      sum -= q.front();
      q.pop();
    }
  }

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
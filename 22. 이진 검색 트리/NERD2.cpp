#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

void Solve()
{
  map<int, int> coords;

  int N;
  cin >> N;

  long long ans = 0;
  while(N--)
  {
    int p, q;
    cin >> p >> q;
    auto iter = coords.upper_bound(p);

    if(iter == coords.end() || iter->second <= q)
    {
      auto iter2 = coords.lower_bound(p);
      if(iter2 != coords.begin())
        iter2 = prev(iter2);
        
      while(!coords.empty() && iter2->first < p && iter2->second < q)
      {
        iter2 = coords.erase(iter2);
        if(iter2 == coords.begin())
          break;

        iter2 = prev(iter2);
      }

      coords.insert({p, q});
      ans += (long long)coords.size();
      continue;
    }

    if(iter->second > q)
    {
      ans += (long long)coords.size();
      continue;
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
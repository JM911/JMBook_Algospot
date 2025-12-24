#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int main()
{
  FASTIO;

  const int MOD = 1000000007;
  vector<int> tot(101, 0);
  vector<int> sym(101, 0);

  tot[0] = 1;
  tot[1] = 1;
  // tot[2] = 2;
  for(int i=2; i<=100; ++i)
  {
    tot[i] = tot[i-1] + tot[i-2];
    tot[i] %= MOD;
  }

  sym[0] = 1;
  sym[1] = 1;
  sym[2] = 2;
  sym[3] = 1;
  for(int i=4; i<=100; ++i)
  {
    sym[i] = sym[i-2] + sym[i-4];
    sym[i] %= MOD;
  }

  int C;
  cin >> C;

  while(C--)
  {
    int n;
    cin >> n;

    int ans = tot[n] - sym[n];
    if(ans < 0)
      ans += MOD;
    
    cout << ans << "\n";
  }
}
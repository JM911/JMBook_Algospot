#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int MOD = 10000000;
int cacheN[105];
int cache[105][105][105];

int Poly(int n, int y, int b)
{
  if(n <= 0 || y <= 0 || b <= 0) return 0;
  if(n < y + b - 1) return 0;

  if(cache[n][y][b] >= 0)
    return cache[n][y][b];
  
  int ret = 0;
  for(int j=1; j<=n-b; ++j)
  {
    ret += (b + j - 1) * Poly(n-b, y-1, j);
    ret %= MOD;
  }

  cache[n][y][b] = ret;
  return ret;
}

int Solve(int n)
{
  if(cacheN[n] > 0)
    return cacheN[n];
  
  for(int i=1; i<=n; ++i)
  {
    for(int j=1; j<=n-i+1; ++j)
    {
      cacheN[n] += Poly(n, i, j);
      cacheN[n] %= MOD;
    }
  }
  
  return cacheN[n];
}

int main()
{
  FASTIO;

  fill(&cacheN[0], &cacheN[105], 0);
  fill(&cache[0][0][0], &cache[104][104][105], -1);

  for(int i=1; i<=100; ++i)
  {
    cache[i][1][i] = 1;
  }

  int C;
  cin >> C;
  while(C--)
  {
    int n;
    cin >> n;
    cout << Solve(n) << "\n";
  }
}
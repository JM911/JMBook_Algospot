#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

double dp[1010][1010];

int main()
{
  FASTIO;

  int t;
  cin >> t;

  cout << fixed;
  cout.precision(10);

  fill(&dp[0][0], &dp[0][0] + 1010 * 1010, 0.0);

  dp[0][0] = 1.0;
  for (int i = 1; i <= 1000; ++i)
  {
    dp[i][0] = 1.0;
    dp[i][1] = 0.25 * dp[i-1][0] + 0.75;

    for (int j = 2; j <= 1000; ++j)
    {
      dp[i][j] = 0.25 * dp[i-1][j-1] + 0.75 * dp[i-1][j-2];
    }
  }

  while(t--)
  {
    int n, m;
    cin >> n >> m;
    cout << dp[m][n] << "\n";
  }
}
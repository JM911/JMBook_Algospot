#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

void Solve()
{
  int n, d, p;
  cin >> n >> d >> p;

  vector<vector<int>> adj(n, vector<int>(n));
  vector<int> adjCount(n, 0);
  vector<vector<double>> prob(105, vector<double>(n, 0));
  vector<vector<double>> probEach(n, vector<double>(n));

  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
    {
      cin >> adj[i][j];
      
      if(adj[i][j] == 1)
        ++adjCount[i];
    }
  
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      if(adj[i][j] == 1)
        probEach[i][j] = 1.0 / (double)adjCount[i];

  // int firstN = 0;
  // for(int i=0; i<n; ++i)
  //   if(adj[p][i] == 1)
  //     ++firstN;

  prob[0][p] = 1.0;
  for(int k=1; k<=d; ++k)
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
        prob[k][i] += prob[k-1][j] * probEach[j][i];

  int t;
  cin >> t;

  while(t--)
  {
    int q;
    cin >> q;
    cout << prob[d][q] << " ";
  }

  cout << "\n";
}

int main()
{
  FASTIO;

  cout << fixed;
  cout.precision(8);

  int c;
  cin >> c;
  while(c--)
  {
    Solve();
  }
}
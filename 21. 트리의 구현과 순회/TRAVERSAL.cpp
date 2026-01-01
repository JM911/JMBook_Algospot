#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

void Solve(const vector<int>& pre, const vector<int>& in)
{
  if(pre.size() == 0)
    return;

  int root = pre[0];
  int rootIdx = -1;
  for(int i=0; i<in.size(); ++i)
    if(root == in[i])
    {
      rootIdx = i;
      break;
    }
  
  int leftSize = rootIdx;
  int rightSize = in.size() - leftSize - 1;

  vector<int> leftPre, rightPre, leftIn, rightIn;
  for(int i=1; i<pre.size(); ++i)
  {
    if(i <= leftSize)
      leftPre.push_back(pre[i]);
    else
      rightPre.push_back(pre[i]);
  }

  for(int i=0; i<in.size(); ++i)
  {
    if(i<rootIdx)
      leftIn.push_back(in[i]);
    if(i>rootIdx)
      rightIn.push_back(in[i]);
  }

  Solve(leftPre, leftIn);
  Solve(rightPre, rightIn);
  cout << root << " ";
}

int main()
{
  FASTIO;

  int C;
  cin >> C;
  while(C--)
  {
    int N;
    cin >> N;

    vector<int> pre(N), in(N);
    for(auto& elem : pre)
      cin >> elem;
    
    for(auto& elem : in)
      cin >> elem;
    
    Solve(pre, in);
    cout << "\n";
  }
}
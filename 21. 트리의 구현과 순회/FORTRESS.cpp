#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

struct Wall
{
  int x, y, r;

  int id = -1;
  int p = -1;
  vector<int> c;
};

void ResolveWall(const vector<Wall>& walls, Wall& a, Wall& b)
{
  int sqrDist = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  int sqrRadDiff = (a.r - b.r) * (a.r - b.r);

  if(sqrDist > sqrRadDiff)
    return;
  
  if(a.r < b.r)
  {
    if(a.p >= 0 && walls[a.p].r < b.r)
      return;

    a.p = b.id;
    b.c.push_back(a.id);
  }
  else
  {
    if(b.p >= 0 && walls[b.p].r < a.r)
      return;
    
    b.p = a.id;
    a.c.push_back(b.id);
  }
}

// ret: dist, height
pair<int, int> GetLongestDist(const vector<Wall>& walls, int rootIdx)
{
  Wall root = walls[rootIdx];
  if(root.c.empty())
    return {0, 0};

  if(root.c.size() == 1)
  {
    pair<int, int> cInfo = GetLongestDist(walls, root.c[0]);
    int retDist = cInfo.first;
    retDist = max(retDist, cInfo.second + 1);
    
    return {retDist, cInfo.second + 1};
  }

  int retDist = 0;
  int retHeight = 0, secHeight = 0;
  for(auto elem : root.c)
  {
    pair<int, int> curInfo = GetLongestDist(walls, elem);
    retDist = max(retDist, curInfo.first);
    if(curInfo.second > retHeight)
    {
      secHeight = retHeight;
      retHeight = curInfo.second;
    }
    else if(curInfo.second > secHeight)
      secHeight = curInfo.second;
  }

  retDist = max(retDist, retHeight + secHeight + 2);
  return {retDist, retHeight + 1};
}

void Solve()
{
  int N;
  cin >> N;

  vector<Wall> walls(N);
  for(int i=0; i<N; ++i)
  {
    cin >> walls[i].x >> walls[i].y >> walls[i].r;
    walls[i].id = i;
  }

  for(int i=0; i<N; ++i)
    for(int j=i+1; j<N; ++j)
      ResolveWall(walls, walls[i], walls[j]);
  
  for(int i=0; i<N; ++i)
  {
    vector<int> realC;
    for(auto elem : walls[i].c)
    {
      if(walls[elem].p == i)
        realC.push_back(elem);
    }
    walls[i].c = realC;
  }

  int rootIdx = -1;
  for(int i=0; i<N; ++i)
    if(walls[i].p == -1)
      rootIdx = i;
  
  pair<int, int> ans = GetLongestDist(walls, rootIdx);
  cout << ans.first << "\n";
}

int main()
{
  FASTIO;

  int C;
  cin >> C;

  while(C--)
    Solve();
}
#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

void Solve()
{
  string s;
  cin >> s;

  stack<char> st;
  for(char c : s)
  {
    if(c == '(' || c == '{' || c == '[')
    {
      st.push(c);
      continue;
    }

    if(st.empty())
    {
      cout << "NO\n";
      return;
    }

    if((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{'))
    {
      st.pop();
      continue;
    }
  }

  if(st.empty())
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main()
{
  FASTIO;

  int C;
  cin >> C;

  while(C--)
    Solve();
}
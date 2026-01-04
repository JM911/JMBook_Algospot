#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

struct Node;
using KeyType = int;
using NodePair =  pair<Node*, Node*>;

struct Node
{
  KeyType key;
  int priority = rand();
  size_t size = 1;
  
  Node* left = nullptr;
  Node* right = nullptr;

  Node(const KeyType& _key) : key(_key)
  { }

  void setLeft(Node* newLeft)
  {
    left = newLeft;
    calcSize();
  }

  void setRight(Node* newRight)
  {
    right = newRight;
    calcSize();
  }

  void calcSize()
  {
    size = 1;
    if(left != nullptr)
      size += left->size;
    if(right != nullptr)
      size += right->size;
  }
};

NodePair split(Node* const root, KeyType key)
{
  if(root == nullptr)
    return {nullptr, nullptr};

  if(root->key < key)
  {
    NodePair p = split(root->right, key);
    
    root->setRight(p.first);
    return {root, p.second};
  }
  else
  {
    NodePair p = split(root->left, key);
    
    root->setLeft(p.second);
    return {p.first, root};
  }
}

Node* insert(Node* const root, Node* const node)
{
  if(root == nullptr)
    return node;

  if(root->priority > node->priority)
  {
    if(root->key > node->key)
      root->setLeft(insert(root->left, node));
    else
      root->setRight(insert(root->right, node));
    
    return root;
  }
  else
  {
    NodePair p = split(root, node->key);
    node->setLeft(p.first);
    node->setRight(p.second);
    return node;
  }

  return nullptr;
}

Node* merge(Node* const a, Node* const b)
{
  if(a == nullptr)
    return b;
  if(b == nullptr)
    return a;

  if(a->priority > b->priority)
  {
    a->setRight(merge(a->right, b));
    return a;
  }
  else
  {
    b->setLeft(merge(a, b->left));
    return b;
  }
}

Node* erase(Node* const root, KeyType key)
{
  if(root == nullptr)
    return nullptr;

  if(root->key > key)
    root->setLeft(erase(root->left, key));
  else if(root->key < key)
    root->setRight(erase(root->right, key));
  else
    return merge(root->left, root->right);

  return root;
}

// k 번째 원소 반환
Node* kth(Node* const root, int k)
{
  if(root == nullptr)
    return nullptr;

  int ls = 0;
  if(root->left != nullptr)
    ls = root->left->size;
  
  int rootIdx = ls + 1;
  if(k == rootIdx)
    return root;
  if(k < rootIdx)
    return kth(root->left, k);
  if(k > rootIdx)
    return kth(root->right, k - rootIdx);

  return nullptr;
}

// key 값보다 작은 원소 개수 반환
int countLessThan(Node* const root, KeyType key)
{
  if(root == nullptr)
    return 0;

  int ret = 0;

  if(root->key < key)
  {
    ++ret;
    
    if(root->left != nullptr)
      ret += root->left->size;
    
    ret += countLessThan(root->right, key);
  }
  else
  {
    ret += countLessThan(root->left, key);
  }
  return ret;
}

void Solve()
{
  int N;
  cin >> N;

  vector<int> kan(N);
  for(auto& elem : kan)
    cin >> elem;

  Node* root = new Node(1);
  for(int i=2; i<=N; ++i)
    root = insert(root, new Node(i));

  stack<int> ans;
  for(int i=N-1; i>=0; --i)
  {
    int k = (i+1) - kan[i];
    int num = kth(root, k)->key;
    ans.push(num);
    root = erase(root, num);
  }

  while(!ans.empty())
  {
    cout << ans.top() << " ";
    ans.pop();
  }
  cout << "\n";
}

int main()
{
  FASTIO;

  int C;
  cin >> C;

  while(C--)
    Solve();
}
//
// different ways of doing in/pre/post order traversal
//
// Zhenbang Chen
// Jul 19, 2017
//
// ------
//
// input:
// 10 // lines
// 0 7 2 // key value, left child, right child
// 10 -1 -1
// 20 -1 6
// 30 8 9 
// 40 3 -1 
// 50 -1 -1 
// 60 1 -1 
// 70 5 4 
// 80 -1 -1 
// 90 -1 -1

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order(int root_index = 0) {
    static vector<int> result;
    if (root_index < 0) return result;
    in_order(left[root_index]);
    result.push_back(key[root_index]);
    in_order(right[root_index]);
    return result;
  }

  vector <int> in_order_loop(int root_index = 0) {
    vector<int> result;
    std::stack<int> sequence;
    //sequence.push(root_index);
    int p = root_index;
    while (!sequence.empty() || p >= 0){
      if (p==-1){
        p = sequence.top();
        sequence.pop();
        result.push_back(key[p]);
        p = right[p];
        //sequence.push(p);
      } else {
        sequence.push(p);
        p = left[p];
      }
    }
    return result;
  }

  vector <int> in_order_loop2(int root_index = 0) {
    vector<int> result;
    std::stack<int> sequence;
    //sequence.push(root_index);
    int p = root_index;
    while (!sequence.empty() || p >= 0){
      while (p >= 0){
        sequence.push(p);
        p = left[p];
      }
      p = sequence.top();
      sequence.pop();
      result.push_back(key[p]);
      p = right[p];
    }
    return result;
  }

  vector <int> pre_order(int root_index = 0) {
    static vector<int> result;
    if (root_index < 0) return result;
    result.push_back(key[root_index]);
    pre_order(left[root_index]);
    pre_order(right[root_index]);
    return result;
  }

  vector <int> pre_order_loop(int root_index = 0) {
    vector<int> result;
    std::stack<int> sequence;
    int p = root_index;
    while (!sequence.empty() || p >= 0){
      if (p==-1){
        p = sequence.top();
        sequence.pop();
        p = right[p];
        //sequence.push(p);
      } else {
        result.push_back(key[p]);
        sequence.push(p);
        p = left[p];
      }
    }
    return result;
  }

  vector <int> pre_order_loop2(int root_index = 0) {
    vector<int> result;
    std::stack<int> sequence;
    int p;
    sequence.push(root_index);
    while (!sequence.empty()){
      p = sequence.top();
      sequence.pop();
      result.push_back(key[p]);
      if (right[p] >= 0) sequence.push(right[p]);
      if (left[p] >= 0) sequence.push(left[p]);
    }
    return result;
  }


  vector <int> post_order(int root_index = 0) {
    static vector<int> result;
    if (root_index < 0) return result;
    post_order(left[root_index]);
    post_order(right[root_index]);
    result.push_back(key[root_index]);
    return result;
  }

  vector <int> post_order_loop(int root_index = 0) {
    vector<int> result;
    std::stack<int> sequence;
    std::stack<int> roots;
    int p = root_index;
    bool from_right = false;
    while (!sequence.empty() || p >= 0){
      if (p==-1){
        p = sequence.top();
        sequence.pop();
        if (from_right){
          while (roots.top() != p){
            result.push_back(key[roots.top()]);
            roots.pop();
          }
        }
        p = right[p];
        from_right = true;
      } else {
        sequence.push(p);
        roots.push(p);
        p = left[p];
        from_right = false;
      }
    }
    while (!roots.empty()){
      result.push_back(key[roots.top()]);
      roots.pop();
    }
    return result;
  }


  vector <int> post_order_loop2(int root_index = 0) {
    vector<int> result, tmp;
    std::stack<int> sequence;
    int p;
    sequence.push(root_index);
    while (!sequence.empty()){
      p = sequence.top();
      sequence.pop();
      tmp.push_back(key[p]);
      if (left[p] >= 0) sequence.push(left[p]);
      if (right[p] >= 0) sequence.push(right[p]);
    }
    // reverse vector
    result.reserve(tmp.size());
    for (auto rit = tmp.rbegin(); rit != tmp.rend(); ++rit)
      result.push_back(*rit);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order_loop());
  print(t.in_order_loop2());
  print(t.pre_order());
  print(t.pre_order_loop2());
  print(t.post_order());
  print(t.post_order_loop2());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

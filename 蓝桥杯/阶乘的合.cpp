#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define SZ(v) ((int)v.size())
#define pii pair<int, int>
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef double db;
using namespace std;
const int N = 2e5 + 10;
int _;

int n;
int x;
map<int, int> mp; // [k, n] 记录当前阶乘以及个数，k代表阶乘值，n代表阶乘个数
int ans;

void
solve()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mp[x]++; // 初始值
  }
  for (auto a : mp) {
    ans = max(ans, a.fi); // 记录最大阶乘
    if (a.se % (a.fi + 1) == 0) { // 判断当前的阶乘是否可以合并到比他大1的阶乘内
      mp[a.fi + 1] += a.se / (a.fi + 1); // 合并阶乘
    } else {
      break; // 不能合并则，当前阶乘就是得到的最大公因数阶乘
    }
  }
  cout << ans << "\n";
}

int
main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
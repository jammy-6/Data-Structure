#include <bits/stdc++.h>
using namespace std;
int
main()
{
  // 请在此输入您的代码
  int num;
  cin >> num;
  string s, t;
  getline(cin, s);
  for (int i = 0; i < num; i++) {
    getline(cin, s);
    getline(cin, t);
    if (s.size() != t.size()) {
      cout << -1 << endl;
      continue;
    }
    bool rs = (s[0] == t[0]) && (s[s.size() - 1] == t[s.size() - 1]);
    if (!rs) {
      cout << -1 << endl;
      continue;
    }
    int count = 0;
    for (int i = 1; i < t.size() - 1; i++) {
      if (t[i] != s[i]) {
        if (t[i] == t[i - 1] || t[i] == t[i + 1]) {
          rs = false;
          break;
        } else {
          count++;
        }
      }
    }
    if (!rs) {
      cout << -1 << endl;
    } else {
      cout << count << endl;
    }
  }
  return 0;
}
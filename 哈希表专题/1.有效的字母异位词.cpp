
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int record[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      record[s[i] - 'a']++;
    }

    for (int i = 0; i < t.size(); i++) {
      if (record[t[i] - 'a'] > 0) {
        record[t[i] - 'a']--;
      } else {
        return false;
      }
    }

    for (int i = 0; i < 26; i++) {
      if (record[i] != 0)
        return false;
    }
    return true;
  }
};
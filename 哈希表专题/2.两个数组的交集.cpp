
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> uni;
    for (int i = 0; i < nums1.size(); i++) {
      uni.insert(nums1[i]);
    }
    unordered_set<int> rs;
    for (int i = 0; i < nums2.size(); i++) {
      if (uni.count(nums2[i])) {
        rs.insert(nums2[i]);
      }
    }
    return vector<int>(rs.begin(), rs.end());
  }
};
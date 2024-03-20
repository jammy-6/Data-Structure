#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int curSum = 0;
    int min = INT_MAX; // 从起点出发，油箱里的油量最小值
    for (int i = 0; i < gas.size(); i++) {
      int rest = gas[i] - cost[i];
      curSum += rest;
      if (curSum < min) {
        min = curSum;
      }
    }
    if (curSum < 0)
      return -1; // 情况1
    if (min >= 0)
      return 0; // 情况2
                // 情况3
    for (int i = gas.size() - 1; i >= 0; i--) {
      int rest = gas[i] - cost[i];
      min += rest;
      if (min >= 0) {
        return i;
      }
    }
    return -1;
  }

  //从局部最优出发
  int canCompleteCircuit_v2(vector<int> &gas, vector<int> &cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
      curSum += gas[i] - cost[i];
      totalSum += gas[i] - cost[i];
      if (curSum < 0) { // 当前累加rest[i]和 curSum一旦小于0
        start = i + 1;  // 起始位置更新为i+1
        curSum = 0;     // curSum从0开始
      }
    }
    if (totalSum < 0)
      return -1; // 说明怎么走都不可能跑一圈了
    return start;
  }
};
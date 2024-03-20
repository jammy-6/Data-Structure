/*
 * 选择排序
 * 思路：找最小元素，放到最终位置
 * 特点：时间：O(n²)、非稳定排序
 * 适用：数据量少
 */

#include <bits/stdc++.h>
using namespace std;

class Select
{
public:
  void mysort(vector<int>& nums)
  {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      int minPos = i;
      for (int j = i + 1; j < n; j++) {
        if (nums[j] < nums[minPos]) {
          minPos = j;
        }
      }
      int temp = nums[i];
      nums[i] = nums[minPos];
      nums[minPos] = temp;
    }
  }
};

int
main()
{
  vector<int> nums = { 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Select select;
  select.mysort(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}
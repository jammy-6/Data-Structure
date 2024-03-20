/*
 * 希尔排序
 * 思路：间隔分组+自定义排序（这里给出的是冒泡）
 * 特点：时间：O(nlogn)、非稳定排序
 * 适用：数据量大
 */

#include <bits/stdc++.h>
using namespace std;

class Shell
{
public:
  void mysort(vector<int>& nums)
  {
    int n = nums.size();
    int gap = n / 2;
    while (gap > 0) {
      for (int j = gap; j < n; j++) {
        int i = j;
        while (i >= gap && nums[i] < nums[i - gap]) {
          int temp = nums[i];
          nums[i] = nums[i - gap];
          nums[i - gap] = temp;
          i -= gap;
        }
      }
      gap /= 2;
    }
  }
};
int
main()
{
  vector<int> nums = { 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Shell shell;
  shell.mysort(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}
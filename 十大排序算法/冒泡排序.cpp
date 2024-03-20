/*
 * 冒泡排序
 * 比较交换相邻元素
 * 思路简单，仅学习用
 */
#include <bits/stdc++.h>
using namespace std;

class Bubble
{
public:
  void mysort(vector<int>& nums)
  {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
        }
      }
    }
  }
};
int
main()
{
  vector<int> nums = { 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Bubble bubble;
  bubble.mysort(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
/*
 * 快速排序
 * 思路：选择中轴元素，比它小的放左，比它大的放右（代码过程很像
 * 小丑在扔三个小球） 特点：时间：O(nlogn)、空间：O(logn)、非稳定
 * 适用：广泛（最快）
 */
class Quick
{
public:
  void mysort(vector<int>& nums, int start, int end)
  {
    if (start >= end)
      return;
    int left = start;
    int right = end;
    int temp = nums[left];
    while (left < right) {
      while (left < right && nums[right] > temp)
        right--;
      nums[left] = nums[right];
      while (left < right && nums[left] < temp)
        left++;
      nums[right] = nums[left];
    }
    nums[left] = temp;
    mysort(nums, start, left - 1);
    mysort(nums, left + 1, end);
  }
};

void
quicksort(vector<int>& nums, int begin, int end)
{
  if (begin >= end)
    return;
  int l = begin, r = end;
  int pivot = nums[l];
  while (l < r) {
    while (l < r && nums[r] > pivot)
      r--;
    nums[l] = nums[r];
    while (l < r && nums[l] < pivot)
      l++;
    nums[r] = nums[l];
  }
  nums[l] = pivot;
  quicksort(nums, begin, l - 1);
  quicksort(nums, l + 1, end);
}

int
main()
{
  vector<int> nums = { 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Quick quick;
  quicksort(nums, 0, nums.size() - 1);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
/*
 * 归并排序
 * 思路：递归思想
 * 特点：时间：O(nlogn)、空间：O(n)——非原地
 * 适用：不受数据影响，所需空间与n成正比
 */
class Merge
{
public:
  void mysort(vector<int>& nums, int left, int right)
  {
    if (left < right) {
      int mid = (right + left) / 2;
      mysort(nums, left, mid);
      mysort(nums, mid + 1, right);
      merge(nums, left, right);
    }
    return;
  }
  void merge(vector<int>& nums, int left, int right)
  {
    vector<int> temp(nums.size());
    int mid = (right + left) / 2;
    int p = left;
    int q = mid + 1;
    int k = left;
    while (p <= mid && q <= right) {
      if (nums[p] < nums[q])
        temp[k++] = nums[p++];
      else
        temp[k++] = nums[q++];
    }
    while (p <= mid)
      temp[k++] = nums[p++];
    while (q <= right)
      temp[k++] = nums[q++];
    for (int i = left; i <= right; i++)
      nums[i] = temp[i];
  }
};
int
main()
{
  vector<int> nums = { 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Merge merge;
  merge.mysort(nums, 0, nums.size() - 1);
  for (int num : nums)
    cout << num << " ";
  return 0;
}
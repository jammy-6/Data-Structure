/*
 * 插入排序
 * 思路：抓牌一样，插入当前手牌中的适当位置
 * 特点：时间：O(n²)
 * 适用：基本有序
 */
#include <bits/stdc++.h>
using namespace std;

class Insert
{
public:
  // 插入排序线性查找版本
  void mysort_v1(vector<int>& nums)
  {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      int pos = i - 1;
      int cur = nums[i];
      while (pos >= 0 && cur < nums[pos]) {
        nums[pos + 1] = nums[pos];
        pos--;
      }
      nums[pos + 1] = cur;
    }
  }

  // 插入排序二分查找版本
  void mysort_v2(vector<int>& nums)
  {
    int n = nums.size();
    int l, r, mid;
    for (int i = 1; i < n; i++) {
      int cur = nums[i];
      l = 0, r = i - 1;
      while (r >= l) {
        mid = (r + l) / 2;
        if (nums[mid] <= cur)
          l = mid + 1;
        else
          r = mid - 1;
      }
      // l最终指向第一个大于cur的位置
      for (int j = i; j > l; j--) {
        nums[j] = nums[j - 1];
      }
      nums[l] = cur;
    }
  }
};
int
main()
{
  vector<int> nums = { 11, 11, 33, 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Insert insert;
  insert.mysort_v2(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}
/*
 * 计数排序
 * 思路：借助足够大的辅助数组，把数字排在一个相对位置不会错的地方，最后并拢
 * 特点：时间：O(n+k)、空间：O(n+k)——非原地
 * 适用：max和min的差值不大
 */

#include <bits/stdc++.h>
using namespace std;

class Count
{
public:
  void mysort(vector<int>& nums, int min, int max)
  {
    vector<int> temp(max - min + 1);
    for (int num : nums) {
      temp[num - min]++;
    }
    int index = 0;
    for (int i = 0; i < temp.size(); i++) {
      int cnt = temp[i];
      while (cnt != 0) {
        nums[index] = i + min;
        index++;
        cnt--;
      }
    }
  }
};
int
main()
{
  vector<int> nums = { 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Count count;
  count.mysort(nums, 0, 9);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}
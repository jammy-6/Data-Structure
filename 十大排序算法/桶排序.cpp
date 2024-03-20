#include <bits/stdc++.h>
using namespace std;
/*
 * 桶排序
 * 思路：先粗略分类分桶，再各桶排序
 * 特点：时间：O(n+k)、空间：O(n+k)——非原地
 * 适用：均匀分布的数据
 */
class Bucket
{
public:
  void mysort(vector<int>& nums)
  {
    // （1）初始化桶
    int n = nums.size();
    vector<list<int>> buckets(n);
    // （2）数据放入桶并完成排序
    for (int num : nums) {
      int index = getBucketIndex(num);
      insertSort(buckets[index], num);
    }
    // （3）从桶取数据，放入nums
    int index = 0;
    for (list<int> bucket : buckets) {
      for (int num : bucket) {
        nums[index] = num;
        index++;
      }
    }
  }
  // 辅助函数一：获得桶的序号
  int getBucketIndex(int num) { return num / 3; }
  // 辅助函数二：把数据插入对应桶(这里用的插入排序)
  void insertSort(list<int>& bucket, int num)
  {
    int n = bucket.size();
    bool flag = true;
    for (auto it = bucket.begin(); it != bucket.end(); it++) {
      if (num <= *it) {
        bucket.insert(it, num);
        flag = false;
        break;
      }
    }
    if (flag)
      bucket.push_back(num);
  }
};
int
main()
{
  vector<int> nums = { 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Bucket b;
  b.mysort(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}

// 注： 桶排序 的 C++实现 我磕磕绊绊，其中遇到了以下困难，希望以后注意：
// 1. vector<list<int>> buckets(n); 的数据结构照顾到频繁插入
// 2. list 结构无法根据索引直接获取值，所以需要 迭代器 遍历
// 3.获取桶序号的函数 return num / 3; ，一定要确保大小顺序。比如一开始我用的 num
// % 3 导致 大小错开了。
// 4. insertSort 函数里的 flag 判断很精妙，尾插必不可少
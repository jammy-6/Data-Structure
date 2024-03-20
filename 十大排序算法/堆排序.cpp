#include <bits/stdc++.h>
using namespace std;
/*
 * 堆排序
 * 思路：升序用大顶堆，每次调整后把最大的移出，再调整...
 * 特点：时间：O(nlogn)、非稳定
 * 适用：数据结构学习
 */
class Heap
{
public:
  void mysort(vector<int>& nums)
  {
    int n = nums.size();
    // （1）构造初始堆
    // 从第一个非叶子节点（倒数第二行最后一个）开始调整
    // 左右孩子节点中较大的交换到父节点中
    // 注意这里i是自底往上的！
    for (int i = n / 2 - 1; i >= 0; i--) {
      headAdjust(nums, n, i);
    }
    // （2）排序
    // 第一步.交换list[0]（最大）和list[i]
    // 第二步.此时list[0]在堆底，固定住，已排好
    // （for循环的i代表len，i--即每次把最后一个排好的忽略掉）
    // 第三步.把无缘无故提上来的幸运儿list[i]再adjust回它应该在的位置
    // （像石头沉入水底）
    // 下一个循环
    for (int i = n - 1; i > 0; i--) {
      // 交换
      int temp = nums[i];
      nums[i] = nums[0];
      nums[0] = temp;
      // 调整
      headAdjust(nums, i, 0);
    }
  }
  // 辅助函数：调整堆
  // 参数说明：nums代表整个二叉树、len是nums的长度、 i代表三个中的根节点
  void headAdjust(vector<int>& nums, int len, int i)
  {
    int index = 2 * i + 1;
    // 这步while的意义在于把较小的沉下去，把较大的提上来
    while (index < len) {
      // （1）index指向左右孩子较大的那个
      if (index + 1 < len) {
        if (nums[index + 1] > nums[index]) // 说明还有右孩子
        {
          index = index + 1;
        }
      }
      // （2）比较交换大孩子和根节点
      if (nums[index] > nums[i]) {
        // 交换
        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;
        // 更新
        i = index;
        index = 2 * i + 1;
      } else {
        break;
      }
    }
  }
};
int
main()
{
  vector<int> nums = { 9, 7, 5, 3, 1, 0, 8, 4, 6, 2 };
  Heap heap;
  heap.mysort(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}
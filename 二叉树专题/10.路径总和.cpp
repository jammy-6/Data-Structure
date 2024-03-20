#include "TreeNode.h"
#include <bits/stdc++.h>
class Solution
{
private:
  bool traversal(TreeNode* cur, int count)
  {
    if (!cur->left && !cur->right && count == 0)
      return true; // 遇到叶子节点，并且计数为0
    if (!cur->left && !cur->right)
      return false; // 遇到叶子节点直接返回

    if (cur->left) {           // 左
      count -= cur->left->val; // 递归，处理节点;
      if (traversal(cur->left, count))
        return true;
      count += cur->left->val; // 回溯，撤销处理结果
    }
    if (cur->right) {           // 右
      count -= cur->right->val; // 递归，处理节点;
      if (traversal(cur->right, count))
        return true;
      count += cur->right->val; // 回溯，撤销处理结果
    }
    return false;
  }
  // 简化版
  bool hasPathSum_v2(TreeNode* root, int sum)
  {
    if (!root)
      return false;
    if (!root->left && !root->right && sum == root->val) {
      return true;
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
  }

public:
  bool hasPathSum(TreeNode* root, int sum)
  {
    if (root == NULL)
      return false;
    return traversal(root, sum - root->val);
  }
};
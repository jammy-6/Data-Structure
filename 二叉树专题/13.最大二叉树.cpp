#include "TreeNode.h"
#include <bits/stdc++.h>
class Solution
{
public:
  void build(TreeNode*& root, vector<int>& nums, int l, int r)
  {
    if (l > r)
      return;
    int idx = l;
    for (int i = l + 1; i <= r; i++) {
      if (nums[i] > nums[idx])
        idx = i;
    }
    root = new TreeNode(nums[idx]);
    build(root->left, nums, l, idx - 1);
    build(root->right, nums, idx + 1, r);
  }
  TreeNode* constructMaximumBinaryTree(vector<int>& nums)
  {
    TreeNode* root = NULL;
    build(root, nums, 0, nums.size() - 1);
    return root;
  }
};
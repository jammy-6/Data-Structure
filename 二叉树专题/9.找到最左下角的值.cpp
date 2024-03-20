#include "TreeNode.h"
#include <bits/stdc++.h>

// 本题也可以用层序遍历解
class Solution
{
public:
  int maxDepth = INT_MIN;
  int result;
  void traversal(TreeNode* root, int depth)
  {
    if (root->left == NULL && root->right == NULL) {
      if (depth > maxDepth) {
        maxDepth = depth;
        result = root->val;
      }
      return;
    }
    if (root->left) {
      traversal(root->left, depth + 1); // 隐藏着回溯
    }
    if (root->right) {
      traversal(root->right, depth + 1); // 隐藏着回溯
    }
    return;
  }
  int findBottomLeftValue(TreeNode* root)
  {
    traversal(root, 0);
    return result;
  }
};
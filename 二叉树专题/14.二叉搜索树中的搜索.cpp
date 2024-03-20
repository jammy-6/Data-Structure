#include "TreeNode.h"
#include <bits/stdc++.h>

class Solution
{
public:
  TreeNode* searchBST(TreeNode* root, int val)
  {
    if (root == NULL || root->val == val)
      return root;
    if (root->val > val)
      return searchBST(root->left, val);
    if (root->val < val)
      return searchBST(root->right, val);
    return NULL;
  }
  // 迭代法
  TreeNode* searchBST_v2(TreeNode* root, int val)
  {
    while (root != NULL) {
      if (root->val > val)
        root = root->left;
      else if (root->val < val)
        root = root->right;
      else
        return root;
    }
    return NULL;
  }
}
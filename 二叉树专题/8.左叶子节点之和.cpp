#include "TreeNode.h"
#include <bits/stdc++.h>

class Solution
{
public:
  int sumOfLeftLeaves(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    int leftValue = 0;
    if (root->left != NULL && root->left->left == NULL &&
        root->left->right == NULL) {
      leftValue = root->left->val;
    }
    return leftValue + sumOfLeftLeaves(root->left) +
           sumOfLeftLeaves(root->right);
  }

  // 迭代法
  int sumOfLeftLeaves_v2(TreeNode* root)
  {
    stack<TreeNode*> st;
    if (root == NULL)
      return 0;
    st.push(root);
    int result = 0;
    while (!st.empty()) {
      TreeNode* node = st.top();
      st.pop();
      if (node->left != NULL && node->left->left == NULL &&
          node->left->right == NULL) {
        result += node->left->val;
      }
      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }
    return result;
  }
};
#include "TreeNode.h"
#include <bits/stdc++.h>

class Solution
{
public:
  vector<vector<int>> rs;
  void preOrder(TreeNode* root, int targetSum, vector<int>& path)
  {
    if (!root)
      return;
    path.push_back(root->val);
    if (targetSum - root->val == 0 && !root->left && !root->right) {
      rs.push_back(path);
    } else {
      preOrder(root->left, targetSum - root->val, path);
      preOrder(root->right, targetSum - root->val, path);
    }
    path.pop_back();
  }
  vector<vector<int>> pathSum(TreeNode* root, int targetSum)
  {
    vector<int> path;
    preOrder(root, targetSum, path);
    return rs;
  }

  // 后续遍历迭代法
  //  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
  //      if(!root) return rs;
  //      stack<TreeNode*> s;

  //     vector<int> path;
  //     TreeNode *cur = root,*last = NULL;
  //     while(cur || !s.empty()){
  //         if(cur){
  //             s.push(cur);
  //             last=cur;

  //             path.push_back(cur->val);
  //             targetSum=targetSum-cur->val;

  //             cur=cur->left;
  //         }else{
  //             cur  = s.top();
  //             if(cur->right && cur->right!=last){
  //                 cur = cur->right;
  //             }else{
  //                 s.pop();
  //                 if(targetSum==0 && !cur->left && !cur->right){
  //                     rs.push_back(path);
  //                 }
  //                 targetSum+=cur->val;
  //                 path.pop_back();
  //                 last = cur;
  //                 cur=NULL;
  //             }
  //         }
  //     }
  //     return rs;
  // }
};
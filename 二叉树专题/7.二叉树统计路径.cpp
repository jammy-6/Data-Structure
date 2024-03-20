#include "TreeNode.h"
#include <bits/stdc++.h>

class Solution
{
public:
  string constructPath(vector<int>& path)
  {
    string rs;
    for (int i = 0; i < path.size(); i++) {
      rs += to_string(path[i]);
      if (i + 1 != path.size())
        rs += "->";
    }
    return rs;
  }

  // 递归前序遍历方式
  vector<string> rs;
  void postOrder(TreeNode* root, vector<int>& path)
  {
    if (!root)
      return;
    path.push_back(root->val);
    postOrder(root->left, path);
    postOrder(root->right, path);
    if (!root->left && !root->right) { // 找到根节点
      rs.push_back(constructPath(path));
    }
    path.pop_back();
  }
  vector<string> binaryTreePaths(TreeNode* root)
  {
    vector<int> path;
    postOrder(root, path);
    return rs;
  }
  //迭代的后序遍历解法,没遍历到叶子节点，栈中的对象会形成一条路径
  // vector<string> binaryTreePaths(TreeNode* root) {
  //     vector<string> rs;
  //     if(!root) return rs;
  //     stack<TreeNode*>s;
  //     TreeNode *cur = root,*last = NULL;
  //     vector<int> path;
  //     while(cur || !s.empty()){
  //         if(cur){
  //             s.push(cur);
  //             path.push_back(cur->val);
  //             last = cur;
  //             cur = cur->left;
  //         }else{
  //             cur = s.top();
  //             if(cur->right&&cur->right!=last){
  //                 cur = cur->right;
  //             }else{//左右节点皆为空
  //                 if(!cur->left&&!cur->right)
  //                     rs.push_back(constructPath(path));
  //                 s.pop();
  //                 last = cur;
  //                 cur=NULL;
  //                 path.pop_back();
  //             }
  //         }

  //     }
  //     return rs;
  // }
};
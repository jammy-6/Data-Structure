#include "TreeNode.h"
#include <bits/stdc++.h>

class Solution
{
public:
  void build(TreeNode*& root,
             vector<int>& inorder,
             int il,
             int ir,
             vector<int>& postorder,
             int pl,
             int pr)
  {
    if (il > ir || pl > pr)
      return;
    root = new TreeNode(postorder[pr]);

    int idx;
    for (idx = il; idx <= ir; idx++) {
      if (inorder[idx] == postorder[pr])
        break;
    }
    // 切割中序数组
    build(root->left, inorder, il, idx - 1, postorder, pl, pl + (idx - il) - 1);
    build(
      root->right, inorder, idx + 1, ir, postorder, pl + (idx - il), pr - 1);
    return;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
  {
    TreeNode* root;
    build(
      root, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    return root;
  }
  // TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  //     if(inorder.size()==0){
  //         return NULL;
  //     }
  //     int val = postorder.back();
  //     TreeNode *root = new TreeNode(val);

  //     int idx;
  //     for(idx=0;idx<inorder.size();idx++){
  //         if(inorder[idx]==val) break;
  //     }

  //     //切割中序数组
  //     vector<int> in_left  =
  //     vector<int>(inorder.begin(),inorder.begin()+idx); vector<int> in_right
  //     = vector<int>(inorder.begin()+idx+1,inorder.end());
  //     //切割后续数组
  //     postorder.resize(postorder.size()-1);
  //     vector<int> po_left  =
  //     vector<int>(postorder.begin(),postorder.begin()+in_left.size());
  //     vector<int> po_right  =
  //     vector<int>(postorder.begin()+in_left.size(),postorder.end());
  //     root->left = buildTree(in_left,po_left);
  //     root->right = buildTree(in_right,po_right);
  //     return root;
  // }
};
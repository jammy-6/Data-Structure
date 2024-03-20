#include <bits/stdc++.h>
#include "TreeNode.h"
class Solution {
public:
    //前序遍历
    void preOrder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        inOrder(cur->left, vec);  // 左
        inOrder(cur->right, vec); // 右
    }

    //中序遍历
    void inOrder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        inOrder(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
        inOrder(cur->right, vec); // 右
    }

    //后序遍历
    void postOrder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        postOrder(cur->left, vec);  // 左
        postOrder(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中
    }


    vector<int> Traversal(TreeNode* root) {
        vector<int> result;
        preOrder(root, result);
        return result;
    }
};
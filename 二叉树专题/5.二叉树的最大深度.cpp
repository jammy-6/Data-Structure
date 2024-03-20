#include <bits/stdc++.h>
#include "TreeNode.h"


//前序，中序求深度，而后序求高度
//二叉树的最大深度即求头节点的高度
class solution {
public:
    int getdepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftdepth = getdepth(node->left);       // 左
        int rightdepth = getdepth(node->right);     // 右
        int depth = 1 + max(leftdepth, rightdepth); // 中
        return depth;
    }


    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};

//前序解法
// class solution {
// public:
//     int result;
//     void getdepth(TreeNode* node, int depth) {
//         result = depth > result ? depth : result; // 中

//         if (node->left == NULL && node->right == NULL) return ;

//         if (node->left) { // 左
//             depth++;    // 深度+1
//             getdepth(node->left, depth);
//             depth--;    // 回溯，深度-1
//         }
//         if (node->right) { // 右
//             depth++;    // 深度+1
//             getdepth(node->right, depth);
//             depth--;    // 回溯，深度-1
//         }
//         return ;
//     }
//     int maxDepth(TreeNode* root) {
//         result = 0;
//         if (root == NULL) return result;
//         getdepth(root, 1);
//         return result;
//     }
// };

//迭代法
// class solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if (root == NULL) return 0;
//         int depth = 0;
//         queue<TreeNode*> que;
//         que.push(root);
//         while(!que.empty()) {
//             int size = que.size();
//             depth++; // 记录深度
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = que.front();
//                 que.pop();
//                 if (node->left) que.push(node->left);
//                 if (node->right) que.push(node->right);
//             }
//         }
//         return depth;
//     }
// };
#include <bits/stdc++.h>
#include "TreeNode.h"
class Solution {
public:
    

    //前序遍历
    vector<int> preOrder(TreeNode *root){
        vector<int> rs;
        if(!root) return rs;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *cur = s.top();
            rs.push_back(cur->val);
            s.pop();
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
        return rs;
    }

    //中序遍历
    vector<int> inOrder(TreeNode *root){
        vector<int> rs;
        stack<TreeNode *> s;
        TreeNode *cur=root;
        while(cur||!s.empty()){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }else{
                cur=s.top();
                rs.push_back(cur->val);
                s.pop();
                cur=cur->right;
            }
        }
        return rs;
    }
    //后序遍历
    vector<int> postOrder(TreeNode* root) {
        vector<int> rs;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *last = NULL;
        while(cur||!s.empty()){
            if(cur){
                s.push(cur);
                cur=cur->left;
            }else{
                cur=s.top();
                if(cur->right&&cur->right!=last){
                    cur=cur->right;
                }else{
                    s.pop();
                    last = cur;
                    rs.push_back(cur->val);
                    cur=NULL;
                }
            }
        }
        return rs;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rs;
        rs = preOrder(root);
        return rs;
    }
};
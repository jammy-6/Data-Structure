#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val,TreeNode *left,TreeNode *right):val(val),left(left),right(right){}
};

void preTraversal(TreeNode *root,vector<int> &rs){
    if(!root) return;
    rs.push_back(root->val);
    preTraversal(root->left,rs);
    preTraversal(root->right,rs);
}

vector<int> preTraversal_v2(TreeNode *root){
    vector<int> rs;
    if(!root) return rs;
    stack<TreeNode *> s;
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

vector<int> inTraversal_v2(TreeNode *root){
    vector<int> rs;
    stack<TreeNode *> s;
    TreeNode *cur=root;
    while(cur!=NULL||!s.empty()){
        if(cur){
            s.push(cur);
            cur = cur->left;
        }else{
            rs.push_back(s.top()->val);
            s.pop();
            cur=cur->right;
        }
    }
    return rs;
}


int main(){

}
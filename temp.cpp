#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
int getHeight(TreeNode* root){
    if(!root) return 0;
    int leftHeight = getHeight(root->left);
    if(leftHeight==-1) return -1;
    int rightHeight = getHeight(root->right);
    if(rightHeight==-1) return -1;
    return abs(leftHeight-rightHeight)>1?-1:1+max(leftHeight,rightHeight);
}

int getHeight_v2(TreeNode* root){
    if(!root) return 0;
    stack<TreeNode*> s;

    TreeNode *cur = root,*last;
    int rs = 0,depth = 0;
    while(cur || !s.empty()){
        if(cur){
            s.push(cur);
            cur=cur->left;
            depth++;
        }else{
            cur = s.top();
            if(cur->right&&cur->right!=last){
                cur = cur->right;
            }else{
                s.pop();
                last = cur;
                rs = max(rs,depth);
                cur = NULL;
                depth--;
            }

        }
    }
    return rs;
}

bool isBalanced(TreeNode* root) {
    
    if(!root) return true;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode *cur;
    while(!s.empty()){
        cur = s.top();
        s.pop();
        int lh = getHeight_v2(cur->left);
        int rh = getHeight_v2(cur->right);
        int lrdiff = abs(lh-rh);
        cout<<lh<<" "<<rh<<" "<<lrdiff<<endl;
        if(lrdiff>1) return false;
        if(cur->right) s.push(cur->right);
        if(cur->left) s.push(cur->left);
    }
    return true;
    // return getHeight(root)!=-1;
}

TreeNode * constructTree(vector<int> &vec,int idx){
    if(idx>vec.size() || vec[idx]==-1) return NULL;
    else{
        TreeNode * node = new TreeNode(vec[idx]);
        node->left = constructTree(vec,idx*2);
        node->right = constructTree(vec,idx*2+1);
        return node;
    }
}
int main()
{   
    int a=3;

    cout<<rs<<endl;
    // vector<int> vec = {-1,1,2,2,3,3,3,3,4,4,4,4,4,4,-1,-1,5,5};
    // TreeNode *root = constructTree(vec,1);
    // bool rs = isBalanced(root);
    // if(rs)
    //     cout<<"balance";

}
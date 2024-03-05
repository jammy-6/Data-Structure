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
 TreeNode * constructTree(vector<int> &vec,int idx){
    if(idx>vec.size() || vec[idx]==-1) return NULL;
    else{
        TreeNode * node = new TreeNode(vec[idx]);
        node->left = constructTree(vec,idx*2);
        node->right = constructTree(vec,idx*2+1);
        return node;
    }
}
    string constructPath(vector<int> &path){
        string rs;
        for(int i=0;i<path.size();i++){
            rs+=to_string(path[i]);
            if(i+1!=path.size())
                rs+="->";
        }
        return rs;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> rs;
        if(!root) return rs;
        stack<TreeNode*>s;
        TreeNode *cur = root,*last = NULL;
        vector<int> path;
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                path.push_back(cur->val);
                
                last = cur;
                cur = cur->left;
            }else{
                cur = s.top();
                if(cur->right&&cur->right!=last){
                    cur = cur->right;
                }else{//左右节点皆为空
                    if(!cur->left&&!cur->right)
                        rs.push_back(constructPath(path));
                    s.pop();
                    last = cur;
                    cur=NULL;
                    path.pop_back();
                }
            }
            
        }
        return rs;
    }

int main(){
    vector<int> vec = {-1,1,2,3,-1,5};
    TreeNode *root = constructTree(vec,1);
    
    vector<string> rs = binaryTreePaths(root);
    for(int i=0;i<rs.size();i++) cout<<rs[i]<<endl;
}
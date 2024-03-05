#include <bits/stdc++.h>
using namespace std;



vector<int> path;
vector<vector<int>> rs;
int gn;

bool judge(int idx,int pos){
    for(int i=0;i<idx;i++){
        if(path[i]==pos || abs(idx-i)==abs(pos-path[i])) return false;
    }
    return true;
}
void backTracing(int idx){
    if(path.size()==gn){
        rs.push_back(path);
        return;
    }
    for(int i=0;i<gn;i++){
        if(judge(idx,i)){
            path.push_back(i);
            backTracing(idx+1);
            path.pop_back();
        }
    }
    
}
vector<vector<string>> convertToAns(){
    vector<vector<string>> ans;

    for(int i=0;i<rs.size();i++){
        vector<string> curPos;
        for(int j=0;j<rs[i].size();j++){
            string pos;
            for(int k=0;k<gn;k++){
                if(rs[i][j]==k) pos.push_back('Q');
                else pos.push_back('.');
            }
            curPos.push_back(pos);
        }
        ans.push_back(curPos);
    }
    return ans;
}
vector<vector<string>> solveNQueens(int n) {
    gn=n;
    backTracing(0);
    return convertToAns();

}

int main(){
    solveNQueens(4);
}
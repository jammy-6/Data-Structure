#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> rs;
vector<string> path;

bool judge(const string &s){
    if(s.size()>3) return false;
    if(s.size()>=2 &&s[0]=='0') return false;
    if(s.size()==0) return false;
    int seg = stoi(s);
    if(seg>=0 && seg<=255) return true;
    else return false;

}
void backTracing(string &s,int startIdx){
    if(path.size()==3){
        string sub = string(s.begin()+startIdx,s.end());
        if(judge(sub)){
            path.push_back(sub);
            rs.push_back(path);
            path.pop_back();
        }
        return;
    }
    for(int i=startIdx;i<s.size();i++){
        string sub = s.substr(startIdx,i-startIdx+1);
        if(judge(sub)){
            path.push_back(sub);
            backTracing(s,i+1);
            path.pop_back();
        }else return;
        
    }
}
vector<string> restoreIpAddresses(string s) {
    backTracing(s,0);
    vector<string> ans;
    for(int i=0;i<rs.size();i++){
        string temp;
        for(int j=0;j<rs[i].size();j++){
            temp+=rs[i][j];
            if(j+1<rs[i].size()) temp.push_back('.');
        }
        ans.push_back(temp);
    }

    return ans;
}
int main(){
    string s = "1111111";
    restoreIpAddresses(s);
    
}
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    string rs;
    if(s.size()<t.size()) return rs;
    rs = "";

    bool ans = false;
    map<char,int> m;
    for(int i=0;i<t.size();i++){
        m[t[i]]++;
    }
    int flag = m.size();
    int i=0,j=0;
    for(;i<s.size();i++){
        if(m.count(s[i])){
                break;
        }
    }
    j=i;
    for(;j<s.size();j++){
        if(m.count(s[j])){
            m[s[j]]--;
            if(m[s[j]]==0) flag--;
        }
        while(flag==0){
            
            if(j-i+1 <=rs.size()||!ans)
                rs = string(s.begin()+i,s.begin()+j+1);
            ans = true;
            while(flag==0 || !m.count(s[i])){
                if(m.count(s[i])){
                    m[s[i]]++;
                    if(m[s[i]]>0){
                        flag++;
                    }
                }
                i++;
            }
        }
    }
    if(!ans) return "";
    return rs;
}


int main(){
    cout<<minWindow("a","a");

}
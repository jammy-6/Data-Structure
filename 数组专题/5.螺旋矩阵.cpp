
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        vector<int> rs;
        if(array.size()==0) return rs;
        int nr = array.size();
        int nc = array[0].size();
        rs = vector<int>(nr*nc,0);
        int u =0,d = array.size()-1,l=0,r=array[0].size()-1;
        int count=0;
        while(true){

            for(int i=l;i<=r;i++){
                rs[count++] = array[u][i];
            }
            if(++u>d) break;
            for(int i=u;i<=d;i++){
                rs[count++] = array[i][r];
            }
            if(--r<l) break;
            for(int i=r;i>=l;i--){
                rs[count++] = array[d][i];
            }
            if(--d<u) break;
            for(int i=d;i>=u;i--){
                rs[count++] = array[i][l];
            }
            if(++l>r) break;
        }
        return rs;
    }
};
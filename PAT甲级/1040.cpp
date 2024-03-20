#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin,s);

    int left,right,sum=0,max = -1;
    for(int i=0;i<2*s.size();i++){
        
        if(i%2){//奇数,对称轴为一个数
            left = i/2 -1;
            right = i/2 +1;
            sum=1;

        }else{//偶数
            left=i/2;
            right = left+1;
            sum=0;
        }
        
        while(left>=0&&right<s.size()&&s[left--]==s[right++]){
            sum+=2;
        }
        if(sum>max) max = sum;
    }
    cout<<max;

}
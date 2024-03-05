#include <bits/stdc++.h>
using namespace std;
int preChangIdx = -1;
int changeIdx = -1;
int num,g;
bool judge(const vector<int>&vec,int i,int j){
    int count = 0;
    while(i<=j){
        if(vec[i]%g!=0){
            count++;
            preChangIdx=changeIdx;
            changeIdx=i;
        }
        if(count>=2) return false;
        i++;
    }
    return count<=1;
}

int main(){

    cin>>num>>g;
    vector<int> vec(num,0);
    for(int i=0;i<num;i++) 
        cin>>vec[i];
    
    int rs = 0;
    int i=0,j=1;
    if(num<2){
        cout<<0;
        return 0;
    } 
    
    while(j<vec.size()){
        if(judge(vec,i,j)){
            rs+=(j-i);
            j++;
        }else{
            if(preChangIdx!=-1)
                i=preChangIdx+1;
        }
    }
    cout<<rs;
    return 0;
}
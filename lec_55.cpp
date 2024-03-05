#include <bits/stdc++.h>
using namespace std;


bool canJump(vector<int>& nums) {
    int i=0;
    int step,maxCover=i+nums[i];
    while(i<nums.size()-1){
        if(nums[i]==0) 
            return false;
        step=nums[i];
        for(int j=i+1;j<nums.size()&&j<=i+step;j++){
            if(j+nums[j]>maxCover){
                maxCover=j+nums[j];
            }
        }
        i=maxCover;
    }
    return true;
}

int main(){
    vector<int> vec = {5,9,3,2,1,0,2,3,3,1,0,0};
    canJump(vec);
}
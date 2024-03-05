#include <bits/stdc++.h>
using namespace std;


int robRange(vector<int> &nums,int start,int end){
    vector<int> dp(end-start+1,0);
    dp[0] = nums[start];
    dp[1] = max(dp[0],nums[start+1]);
    for(int j=2;j<dp.size();j++){
        dp[j] = max(dp[j-2]+nums[start+j],dp[j-1]);
    }
    return dp[dp.size()-1];
}

int rob(vector<int>& nums) {
    int s = nums.size();
    if(s<=3){
        return *max_element(nums.begin(),nums.end());
    }
    int lMax = robRange(nums,0,s-2);//不考虑右边界
    int rMax = robRange(nums,1,s-1);//不考虑左边界
    return max(lMax,rMax);
}



int main(){
    vector<int> nums = {1,2,3,1};
    cout<<rob(nums);
}
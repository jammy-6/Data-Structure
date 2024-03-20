
#include <bits/stdc++.h>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mm;
        for(int i=0;i<nums.size();i++){
            if(mm.count(target-nums[i])){
                return vector<int>{mm[target-nums[i]],i};
            }else{
                mm[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};
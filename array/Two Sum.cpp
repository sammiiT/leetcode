﻿class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); ++i){
            if(m.count(target-nums[i])){
                res[0]=m[target-nums[i]];
                res[1]=i;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};

/*
target-nums[i] => 剩餘值 (剩餘當作key)
m.count(target-nums[i]) => key存在?

m[target-nums[i]]
m[nums[i]] => 當下的數值,視為剩餘值
*/

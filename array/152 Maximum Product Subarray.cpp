﻿class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> mx(nums.size(),0);
        vector<int> mi(nums.size(),0);
        
        int res = nums[0];
        mx[0] = nums[0];
        mi[0] = nums[0];        
/* 途中會有"中斷"發生; (中斷=截斷); 斷點發生在當下的element, 可以用 max()或 min()函數來做為截斷方式 
mx[i] = max(max(mx[i-1]*nums[i],mi[i-1]*nums[i]),nums[i]);
其中 nums[i]為截斷點.

概念可相通於 53. Maximum Subarray
*/        
        for(int i=1; i<nums.size(); ++i){
            mx[i] = max(max(mx[i-1]*nums[i],mi[i-1]*nums[i]),nums[i]);
            mi[i] = min(min(mx[i-1]*nums[i],mi[i-1]*nums[i]),nums[i]);
            res = max(mx[i],res);
        }      
        return res;
    }
    
    
    int maxProduct_fail(vector<int>& nums) {
        //vector<int> mx(nums.size(),0);
        //vector<int> mi(nums.size(),0);
        int mx,mi;
        int res = nums[0];
        mx = nums[0];
        mi = nums[0];
        for(int i=1; i<nums.size(); ++i){
            mx = max(max(mx*nums[i],mi*nums[i]),nums[i]);
            //上一個mx會影響到這一個mx,會錯誤
            mi = min(min(mx*nums[i],mi*nums[i]),nums[i]);
            res = max(mx,res);
        }
        return res;
    }
    
    
    
    
};

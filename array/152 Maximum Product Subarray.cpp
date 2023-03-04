//===類似題===
153. Find Minimum in Rotated Sorted Array
198. House Robber
//===思路===
(*)Maximum sum subarry參考
-要有截斷點  cur = max(cur+nums[i],nums[i]);
--其中nums[i]就是截斷點, max((-5+4),4)
    
(*)product比較麻煩,因為會遇到負負, 正負
-所以要有兩個比較基準點, 一個是mx,一個是mi
max(max(mx*nums[i],mi*nums[i]),nums[i])
--先比較前一個mx和mi, 乘上當下節點數值      
--比較maximum和minimum
---max(mx*nums[i],mi*nums[i])
   min(mx*nums[i],mi*nums[i])

-再與當下的數值nums[i]做比較, 比較maximum和minimum

-求每次subarray的maximum數值  
-- res = max(mx,res);
//=====
class Solution {
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

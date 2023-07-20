//===類似題===
152. Maximum Product Subarray
2321. Maximum Score Of Spliced Array
1749. Maximum Absolute Sum of Any Subarray
1746. Maximum Subarray Sum After One Operation

//===思路===
1.遍歷數列,累加數值且比較當下數值
cur = max(cur+nums[i],nums[i]);
如果 [-1,-2,....] => 累加到第二個, cur會等於 (-2)

2. 跟之前的maximum做比較
res = max(res,cur);

//===
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int res = INT_MIN;
/*途中會有"中斷"發生; (中斷 = 截斷 = 當下>過去); 斷點發生在當下的element, 可以用 max()或 min()函數來做為截斷方式 
cur = max(cur+nums[i],nums[i]);//當下> 過去結果 => 截斷點在nums[i]; 利用max()函式取出
其中 nums[i]為截斷點.

可以參考 152. Maximum Product Subarray
*/        
        for(int i =0; i<nums.size(); ++i){
            cur = max(cur+nums[i],nums[i]);//reset ??
            res = max(res,cur);//?????????
        }
        return res;
    }
};

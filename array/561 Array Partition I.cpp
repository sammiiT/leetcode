//===類似題===
562. Longest Line of Consecutive One in Matrix
2144. Minimum Cost of Buying Candies With Discount
2155. All Divisions With the Highest Score of a Binary Array
//===思路===
1.先將陣列作排列,兩數差距最小,對應的min和最大
2.相鄰的兩個數值, 一定差距最小;

//======
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i+=2){
            int tmp = min(nums[i],nums[i+1]);//as large as possible
            res+=tmp;
        }
        return res;
    }
};

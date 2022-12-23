//===類似題====
210. Course Schedule II
76. Minimum Window Substring
325. Maximum Size Subarray Sum Equals k
1658. Minimum Operations to Reduce X to Zero
//===思路====


//=========

int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int mi = INT_MAX;
    int l = 0;
    for(int i=0; i<nums.size(); i++){
       sum+=nums[i];//窗口往前移
            
       while(sum>=target){//窗口往後移, 條件是"greater than" or "equal to"
            mi = min(mi,i-l+1);//先判斷minimum
            sum = sum-nums[l];//再移動l
            l++;
        }
    }
    if(mi==INT_MAX) return 0;//如果不滿足條件
    return mi;
}

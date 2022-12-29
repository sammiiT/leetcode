//===類似題===
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
2365. Task Scheduler II

//===思路===
(*)如果依序每一個1的位址都跟相鄰最近的1有 k的間隔, 則1和1之間倆倆絕對有k的間隔
1.遍歷數列一次
2.初始第一個1的boundary設定為條件 1<= nums.length <= 10^5 的範圍;並取負值
2.2則取到第一個1絕對會滿足條件
//====
bool helper0(vector<int>& nums, int k){
    int j = (nums.size()+1)*(-1);
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==1){
            if((i-j-1)>=k) j=i;
            else return false;
        }
    }
    return true;
}
bool kLengthApart(vector<int>& nums, int k) {
    return helper0(nums,k);
}

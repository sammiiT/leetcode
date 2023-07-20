//===類似題===
325. Maximum Size Subarray Sum Equals k
2100. Find Good Days to Rob the Bank
2355. Maximum Number of Books You Can Take
2393. Count Strictly Increasing Subarrays

//===思路====
1.遇到ascending , 累加, 更新 maximum
2.遇到descending, 重新計算累加, 更新maximum
3.遇到重複的數字要重新計算; 

//===
int maxAscendingSum(vector<int>& nums) {
    
    int acc = nums[0];
    int res = acc;//nums[0]

    for(int i=1; i<nums.size(); ++i){
        if(nums[i-1] < nums[i]) {//比前一個大
            acc+=nums[i];
        }else{//nums[i-1]>=nums[i] //小於等於前一個
            acc = nums[i];
        }
        res = max(res,acc);
    }
    return res;
}

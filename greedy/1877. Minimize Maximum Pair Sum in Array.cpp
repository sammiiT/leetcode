//===類似題===
1879. Minimum XOR Sum of Two Arrays
2054. Two Best Non-Overlapping Events
573. Squirrel Simulation
1029. Two City Scheduling

//===思路===
(*)pair數列中的每一個數字, 找出"和"最大的, 且這個最大的"和"卻是"所有可能中最小的"
1. sort數列
2. pair配對取"最後"和"最前"面來配對
3.每次配對都與前一次相比, 取最大值max(x,y)
4. 最後回傳最大值,即為解

//=====
int minPairSum(vector<int>& nums) {
        int mx = 0;
        int l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());
        
        while(l<r){
            mx = max(mx,nums[l]+nums[r]);
            ++l;
            --r;
        }
        return mx;
}

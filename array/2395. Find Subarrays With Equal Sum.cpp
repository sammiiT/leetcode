//===類似題===
416. Partition Equal Subset Sum
1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

//===思路===

bool findSubarrays(vector<int>& nums) {
    int n = nums.size();
    long sum = 0;
    unordered_map<long,long> ump;
        
    sum = nums[0]+nums[1];
    ump[sum]++;

    for(int i=2; i<n; ++i){
        sum+=nums[i];
        sum-=nums[i-2];
        if(ump.count(sum)){ return true; }    
        ump[sum]++;
    }
    return false;
}

//===類似題===
2302. Count Subarrays With Score Less Than K
2750. Ways to Split Array Into Good Subarrays
//===思路===
參考 560 Subarray Sum Equals K

//===
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    unordered_map<int,int> ump;//prefix_sum, count
        //vector<int> sum(n,0);
    int sum = 0;
    int res = 0;

    for(int i=0; i<n; ++i){
        sum = sum + nums[i];
        if(sum==goal) res++;

        int need = sum - goal;
        if(ump.count(need)){
            res = res+ump[need];
        }
        ump[sum]++;
    }
    return res;
}


int helper0(vector<int>& nums, int k){
    int res = INT_MAX;
    sort(nums.begin(),nums.end());
        
    for(int i=k,j=0; i<=nums.size(); i++,j++){
        res = min(res,nums[i-1]-nums[j]);//最大-最小= minimum;一定發生在相鄰連續的子陣列中.
    }
    return res;
}

int minimumDifference(vector<int>& nums, int k) {
    return helper0(nums,k);        
}

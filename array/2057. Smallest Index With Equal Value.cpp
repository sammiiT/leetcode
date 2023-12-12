//===類似題===
2033. Minimum Operations to Make a Uni-Value Grid
2272. Substring With Largest Variance
2659. Make Array Empty
//===思路====
int smallestEqual(vector<int>& nums) {
    int res = INT_MAX;
    for(int i=0;i<nums.size();++i){
        if((i%10)==nums[i]){
            res  = min(res,i);        
        }
    }
    return (res==INT_MAX)?-1:res;
}

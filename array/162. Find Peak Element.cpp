//====類似題===
163. Missing Ranges
852. Peak Index in a Mountain Array
1901. Find a Peak Element II
2137. Pour Water Between Buckets to Make Water Levels Equal
//===思路====

//======
int helper0(vector<int>& nums) {
    if(nums.size()==1) return 0;
    nums.insert(nums.begin(),INT_MIN);
    nums.insert(nums.end(),INT_MIN);
    for(int i=1;i<nums.size()-1;i++){
        if(nums[i-1]<nums[i] && nums[i]>nums[i+1]) return i-1;
    }
    return -1;
}

int helper1(vector<int>& nums){
    if(nums.size()==1) return 0;
    int res = 0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]>nums[i-1]) res = i;
    }
    return res;
}



int helper(vector<int>& nums){
        int ret;
        int i=0,j=1;
        
        nums.push_back(INT_MIN);//當只有兩個element時
        nums.insert(nums.begin(),INT_MIN);//當只有兩個element時
        
        for(;j<nums.size()-1;){
            if((nums[i]<nums[j]) && (nums[j]>nums[j+1])){
                ret = j;
                break;
            }
            i++;
            j++;
        }
        return ret-1;//新增的點,會造成index多1
}
    
int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        return helper(nums);
}

class Solution {
public:
    int missingNumber(vector<int>& nums) {
          sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();++i){
        if(nums[i]!=i) return i;
    }
    return nums.size();
  
    }
};
//========================
int helper(vector<int>& nums){
        sort(nums.begin(),nums.end());
        nums.push_back(nums[nums.size()-1]+1);
        nums.insert(nums.begin(),-1);
        
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i+1]!=nums[i]+1){
                return nums[i]+1;
            }    
        }
        return nums[nums.size()-1];
}

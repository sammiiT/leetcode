class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        int res;
        
        for(int i=0;i<nums.size();++i){
            if(m.count(nums[i])){
                res = nums[i];
                break;
                // return nums[i];
            }
            m[nums[i]]++;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> findDuplicates_OK2(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); ++i){
            m[nums[i]]++;
        }
        for(auto a:m){
            if(a.second>1){
                res.push_back(a.first);
            }
        }
        return res;
    }
    
    
    vector<int> findDuplicates_OK1(vector<int>& nums){
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            int j = abs(nums[i])-1;
            if(nums[j]<0) res.push_back(abs(nums[i]));
            else nums[j]=-nums[j];
        }
        return res;
    }

    vector<int> findDuplicates(vector<int>& nums){
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            int idx = abs(nums[i])-1;
            if(nums[idx]>0) nums[idx]=-nums[idx];
            else{//nums[idx]<0
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }
    
    
};
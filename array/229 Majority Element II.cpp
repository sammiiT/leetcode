class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();++i){
            m[nums[i]]++;
        }
        
        for(auto a: m){
            if(a.second > nums.size()/3.0){
                res.push_back(a.first);
            }
        }
        
        return res;
    }
};
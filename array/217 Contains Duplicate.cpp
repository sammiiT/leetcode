//===類似題===
218. The Skyline Problem
2357. Make Array Zero by Subtracting Equal Amounts
//===思路===
bool helper0(vector<int>& nums) {
    unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++){
        if(m.count(nums[i])){
            return true;
        }
        m[nums[i]]++;
    }
    return false;
}
//====
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
    
    
    bool containsDuplicate2(vector<int>& nums){
        unordered_map<int,int> m;
        
        for(int i=0; i<nums.size(); ++i){
            if(++m[nums[i]]>1) return true;
        }
        return false;
    }
};

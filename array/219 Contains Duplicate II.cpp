class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums,int k){
        int n = nums.size();
        // unordered_map<int,int> m;
        unordered_map<int,int> m;
        
        for(int i=0; i<n; ++i){
            if(m.count(nums[i])){
                if(abs(m[nums[i]]-i)<=k){
                    return true;
                }else{
                    m[nums[i]]=i;//重新定義出現index
                }
            }else{
                m[nums[i]]=i;
            }
        }
        return false;
        
    }
    
    //at most k ; 最多是k
    bool containsNearbyDuplicate_fail(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n && (i+k)<n; ++i){
            
            if(nums[i]==nums[i+k]){
                return true;
            }
        }
        return false;
    }
};
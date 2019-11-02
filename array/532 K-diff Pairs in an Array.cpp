class Solution {
public:
    int findPairs_fail(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        unordered_map<int,int> m;
        int res = 0;
        
        //diff = k;
        for(int i=0;i<nums.size();++i){
            if(m.count(nums[i]+k)){
                res+=1;
            }
            m[nums[i]]++;
        }
        return res;
    }
    
    
    //跟 twoSum算法有點不一樣
    int findPairs(vector<int>& nums, int k){
        if(nums.empty()) return 0;
            
        int res = 0;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();++i){
            m[nums[i]]++;
        }
        
        for(auto a:m){
            if(k==0 && a.second>1) res++;//diff = k = 0
            if(k>0 && m.count(a.first+k)) res++; 
        }
        return res;
        
    }
};
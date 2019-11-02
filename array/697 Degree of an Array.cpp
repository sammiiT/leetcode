class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> m;//key = val v=count
        unordered_map<int,pair<int,int>> pos;//key = val, v= start:end
        int degree = INT_MIN;
        int res = INT_MAX;
        
        for(int i=0;i<n;++i){
            if(++m[nums[i]]==1){
                pos[nums[i]]={i,i};
            }else{
                pos[nums[i]].second = i;
            }
            degree = max(degree,m[nums[i]]);
        }
        
        for(auto a:m){
            if(a.second == degree){
                res = min(res,pos[a.first].second-pos[a.first].first+1);             }
        }
        return res;    

        
    }
};
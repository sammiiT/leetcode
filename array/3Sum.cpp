class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n-2; ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;    
            // if(i==0 || nums[i]!=nums[i-1])//OK statement
            for(int j=i+1,k=n-1;j<k;){
                if(j-1>i && nums[j-1]==nums[j]){//j??:???(j)=???(j-1)
                    ++j;
                }else if(k+1<n && nums[k]==nums[k+1]){//k??:???(k)=???(k+1)
                    --k;
                }else{
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum<0){
                        ++j;
                    }else if(sum>0){
                        --k;
                    }else{//sum==target
                        res.push_back({nums[i],nums[j],nums[k]});
                        ++j;
                        --k;
                    }
                }
            }
     
        }
        return res;
    }
};
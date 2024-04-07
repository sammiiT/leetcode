//=== more challenge===
259. 3Sum Smaller
2367. Number of Arithmetic Triplets
2908. Minimum Sum of Mountain Triplets I
//====
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n-2; ++i){
            
            if(i>0 && nums[i]==nums[i-1]) continue; //避免i重複選取   
            // if(i==0 || nums[i]!=nums[i-1])//OK statement
            for(int j=i+1,k=n-1;j<k;){//在一輪執行完畢之後,可以找出最多n組解, 所以i再增加時,如果數值跟前一個一樣, 會造成重複解.
                if(j-1>i && nums[j-1]==nums[j]){//避免j重複選取
                    ++j;
                }else if(k+1<n && nums[k]==nums[k+1]){//避免k重複選取
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

//=== Time limit Exceeded ===
(*) 三維, 造成超時
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());    
    for(int i=0;i<nums.size();++i){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<nums.size(); ++j){
            if(j>(i+1) && nums[j]==nums[j-1]) continue;
            int target = (-1)*(nums[i]+nums[j]);
            
            for(int k=j+1; k<nums.size(); ++k){
                if(k>j+1 && nums[k]==nums[k-1]) continue;
                if(nums[k]==target) res.push_back({nums[i],nums[j],nums[k]});
            }
        }
    }
    return res;
}


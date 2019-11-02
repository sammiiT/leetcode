class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int i,j,sum,left,right;
        int len = static_cast<int>(nums.size());
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());

//(1)??i,j        
        for(i=0; i<len-3; ++i){
            //??i??
            if(i && nums[i]==nums[i-1]) continue;//skip "i" duplicate
            
            for(j=i+1; j<len-2; ++j){
                //??j??
                if(j-1>i && nums[j]==nums[j-1]) continue;//skip "j" duplicate
                
                sum = target - nums[i]-nums[j];
                left = j+1; right = len-1;

//(2)??left,right   for(int j=i+1,k=nums.size()-1; j<k ;){// 3sum??             
                while(left<right){
                    if(left-1>j && nums[left]==nums[left-1]){++left;}//???duplcate,?????    
                    else if(right+1<len && nums[right]==nums[right+1]){--right;}//???duplicate,?????
                    else{//no duplicate
                        if(nums[left]+nums[right]>sum){
                            --right;    
                        }else if(nums[left]+nums[right]<sum){
                            ++left;
                        }else{//(nums[i]+nums[j]+nums[left]+nums[right]==target)
                            res.push_back({nums[i],nums[j],nums[left],nums[right]});
                            ++left;
                            --right;    
                        }
                    }
                }
                
                
//                 while(left<right){
//                     if(nums[left]+nums[right]==sum){//???????,???duplicate
//                         res.push_back({nums[i],nums[j],nums[left],nums[right]});
//                         ++left;
//                         --right;
//                         while(left<right && nums[left]==nums[left-1]){++left;}
//                         while(left<right && nums[right]==nums[right+1]){--right;}
//                     }else if(nums[left]+nums[right]<sum){
//                         ++left;
//                     }else{//nums[left]+nums[right]>sum
//                         --right;
//                     }                                
//                 }//while(left<right)
            }//for(j...)            
        }//for(i...)
        return res;
    }
};
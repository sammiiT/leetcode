class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
        vector<int> res({nums.size(),0});
        
        
        for(int i=1;i<nums.size();++i){
            int tmp = nums[i];
            int j = i-1;
            
            if(nums[j]>tmp) res[1] = i;
            
            while(j>=0 && nums[j]>tmp){
                nums[j+1]=nums[j];
                --j;
            }
            nums[j+1] = tmp;
            
            if(j!=(i-1)) res[0] = min(res[0],j+1);
        }
        
        if(res[0]==nums.size() && res[1]==0) return 0;
        else return res[1]-res[0]+1;
        // return (res[0]==res[1])?0:res[1]-res[0]+1;
    }
};
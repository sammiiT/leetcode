class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n=nums.size();
        // int i, j;
        // for(i=n-1-1; i>=0; --i){//????,??????????
        //     if(nums[i] < nums[i+1]){//????????
        //         //????, ????????? ???(i)???.
        //         for(j=n-1; j>i; --j){
        //             if(nums[j]>nums[i]){
        //                 swap(nums[i],nums[j]);
        //                 reverse(nums.begin()+i+1,nums.end());
        //                 return;
        //             } 
        //         }
        //     }
        // }
        // reverse(nums.begin(),nums.end());//???????????,????
    
//-----------------------------------------------
        int n=nums.size(), i=n-2, j=n-1;
        //????????????
        while(i>=0 && nums[i]>=nums[i+1]) --i;//??????,i????"-1"; ???: (i>=0)????????i??-1
        if(i>=0){//>=0???, i????? "-1"
            while(nums[j]<=nums[i]){ --j;}
            swap(nums[i],nums[j]);
            
        }
        reverse(nums.begin()+1+i,nums.end());
//----------------------------------------------- 
        
        
        
        
        
    }
};
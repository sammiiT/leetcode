class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        long first=LONG_MIN,second = LONG_MIN;
        if(nums.size()==1) return 0;
        int id =0;
        
        for(int i=0;i<nums.size();++i){
            if(nums[i]>first){
                second = first;
                first = nums[i];
                id = i;
            }else if(nums[i]>second){
                second = nums[i];
            }
        }
        if((first-second)>=second) return id;
        else return -1;
    }
};
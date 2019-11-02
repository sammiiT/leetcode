class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long first = LONG_MIN;
        long second= LONG_MIN;
        long third = LONG_MIN;
        
        //不能將相同值放在同一數列,所以在判斷式中沒有"=="
        for(int i=0;i<nums.size();++i){//time complexity
            if(nums[i]>first){
                third = second;
                second = first;
                first = nums[i];
            }else if(nums[i]<first && nums[i]>second){
                third = second;
                second = nums[i];
            }else if(nums[i]<second && nums[i]>third){
                third = nums[i];
            }
        }
        
        // return (third==LONG_MIN||third==second)? first:third;
        return (third==LONG_MIN)? first:third;
    }
};
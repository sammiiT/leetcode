class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
              int sum=0,minSize,start=-1;
        if(nums.empty()) return 0;
        minSize = numeric_limits<int>::max();
        
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            while(sum>=s){
                minSize=min(i-start,minSize);
                sum=sum-nums[++start];
            }
        }
        if(minSize==numeric_limits<int>::max()){ return 0;}
        
        return minSize;  
    }
};
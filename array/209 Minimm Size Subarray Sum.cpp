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

//===寫法2===
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int i=0,j=0;
        int res = INT_MAX;
        int sum = 0;


        while(i<size){
            sum = sum+nums[i];

            while(sum>=target){//"greater than" or "equal to"
                res = min(res,i-j+1);
                sum = sum - nums[j++];
            }            
            ++i;//sum<target
        }
        return (res==INT_MAX)?0:res;
    }

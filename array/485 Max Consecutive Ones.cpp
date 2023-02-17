//===類似題===
486. Predict the Winner
487. Max Consecutive Ones II
1869. Longer Contiguous Segments of Ones than Zeros
2414. Length of the Longest Alphabetical Continuous Substring
//===思路===
1.遍歷數列, 遇到1就(++count), 並判斷maximum
2.如果遇到0, 將count歸零
3.最後回傳maximum 數值

//====
int helper0(vector<int>& nums) {
    int res = 0;
    int count = 0;
    for(int a:nums){
        if(a) res = max(res,++count);
        else count = 0;
    }
    return res;
}
int findMaxConsecutiveOnes(vector<int>& nums) {
    return helper0(nums);
}
//===
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 0, count=0;
        
        for(int i=0; i<=nums.size(); ++i){
            if(i<nums.size() && nums[i]==1){
                count+=1;
            }else{
                res = max(res,count);
                count=0;
            }
        }
        return res;
    }
};

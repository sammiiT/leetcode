//===類似題===
300. Longest Increasing Subsequence
673. Number of Longest Increasing Subsequence
727. Minimum Window Subsequence
2407. Longest Increasing Subsequence II
//===思路===
(*)若[i-1]<[i] 則 continuous subsequence 累加
(*)若[i-1]>=[i], 則continuous subsequence 重製

(*)參考 128. Longest Consecutive Sequence

int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        int cur = 1;
        for(int i=1;i<nums.size();++i){
            if(nums[i-1]<nums[i]){
                cur+=1;
            }else{
                cur=1;
            }
            res = max(res,cur);
        }
        return res;
}


//===寫法2===
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int len=1;
        int res = 0;
        
        for(int i=1;i<=nums.size();++i){
            if(i<nums.size()&&nums[i]>nums[i-1]){
                len+=1;
            }else{
                res = max(res,len);
                len = 1;
            }
        }
        return res;
    }
};

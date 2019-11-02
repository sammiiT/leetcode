class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        if(nums.empty()) return false;
/*執行過程中, 同時也變更數列中的值
non-decreasing, 前後兩數相等也滿足
                前數小於後數(ascending), 滿足non-decreasing條件
[4,2,3]=>[2,2,3]
ex2: [-1,4,2,3] => [-1,2,2,3]
ex3: [2,3,3,2,4]=> [ 2,3,3,3,4]
*/        
        for(int i=1; i<n; ++i){
            if(nums[i-1]>nums[i]){//(前)大於(當下)
                if(cnt==0) return false;//一次以上變換, 回傳false.
                if(i==1 || nums[i]>=nums[i-2]){//(當下)是否大於(前前)
                    nums[i-1]=nums[i];//(前面)變成(當下) 相同的值//example 2
                }else{//nums[i]<nums[i-2]
                    nums[i]=nums[i-1];//example 3
                }
                cnt--;
            }
        }
        return true;
    }
};
//===類似題===
304. Range Sum Query 2D - Immutable
307. Range Sum Query - Mutable
325. Maximum Size Subarray Sum Equals k
//===思路===
(*)建立一陣列vector<int> sum, 每一個陣列數值是0~i的和
-如果計算left~right之間的和即 sum[right]-sum[left-1];
//=======
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++){
            res+=nums[i];
            sum.push_back(res);
        }
    }
    int sumRange(int left, int right) {
        return (left==0)?sum[right]:(sum[right]-sum[left-1]);    

/*        int n = 0;
        if(left==0) n=0;
        else n = sum[left-1]; 
        return sum[right]-n;*/

/*
    int sumRange(int i, int j) {
        if(ary.empty()) return 0;
        return (i==0)?ary[j]:(ary[j]-ary[i-1]);
    }
*/

    }
private:
    vector<int> sum;
};

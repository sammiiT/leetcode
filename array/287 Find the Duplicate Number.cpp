//===類似題===
609. Find Duplicate File in System
645. Set Mismatch

//===思路====
(*)固定size陣列; vector<int> m(10001,0)
 -  1<=n<=10^5,所以定義 如上vector, 不管如何都constant size的 vector   

int findDuplicate(vector<int>& nums){
    vector<int> m(10001,0);
    for(int a:nums){
        if(++m[a]>=2) return a;
    }
    return -1;
}


//===思路2===
(*)用unordered_map做
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        int res;
        
        for(int i=0;i<nums.size();++i){
            if(m.count(nums[i])){
                res = nums[i];
                break;
                // return nums[i];
            }
            m[nums[i]]++;
        }
        return res;
    }
};

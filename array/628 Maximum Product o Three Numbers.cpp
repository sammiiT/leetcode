class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int res = 1;
//need to consider the negative value.        
        sort(nums.begin(),nums.end());
        res = nums[0]*nums[1]*nums[n-1];
        res = max(res,nums[n-1]*nums[n-2]*nums[n-3]);
        
        return res;
    }
};




//         priority_queue<int> q;
//         for(int i=0; i<n; ++i){
//             q.push(nums[i]);
//         }
//         for(int i=0; i<3; ++i){
//             res*=q.top();
//             q.pop();
//         }
//         return res;
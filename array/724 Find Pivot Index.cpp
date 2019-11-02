class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        vector<int> sum(n,0);
        sum[n-1]=nums[n-1];
        
        for(int i=n-2; i>=0; --i){
            sum[i]=sum[i+1]+nums[i];
        }
        int tmp=0;
        
        for(int i=0; i<n; ++i){
            tmp+=nums[i];
            if(tmp==sum[i]) return i;
        }
        return -1;
    }
};
//有問題:
//[-1,-1,0,0,-1,-1] 會求得3,而不是2;必須反過來算

//         if(nums.empty()) return -1;
//         int n = nums.size();
//         vector<int> sum(n,0);
//         sum[0]=nums[0];
        
//         for(int i=1; i<n; ++i){
//             sum[i]=sum[i-1]+nums[i];
//         }
        
//         int tmp =0;
//         for(int i=n-1; i>=0; --i){
//             tmp+=nums[i];
//             if(tmp==sum[i]){
//                 return i;
//             }
//         }
//         return -1;





//數字皆為positive integer的算法
// if(nums.empty()) return -1;
//         int n = nums.size();
//         vector<int> sum(n,0);
//         unordered_map<int,int> m;
        
//         sum[0]=nums[0];
//         m[nums[0]]=0;
//         for(int i=1; i<n; ++i){
//             sum[i] = sum[i-1]+nums[i];
//             m[sum[i]] = i;
//         }
        
//         for(int i=n-2; i>=0; --i){
//             if(m.count(sum[n-1]-sum[i])){
//                 return i;
//             }
//         }
//         return -1;


//[1,7,3,6,5,6]
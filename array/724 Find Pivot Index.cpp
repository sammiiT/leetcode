//===類似題===
725. Split Linked List in Parts
1991. Find the Middle Index in Array
2270. Number of Ways to Split Array
2219. Maximum Sum Score of Array
//===思路===
[2,1,-1]
=>[2,3,2]
=>[2,0,-1]


[1,2,3]
=>[1,3,6]
=>[6,5,3]


[1,7,3,6,5,6]
=>[1,8,11,17,22,28]
=>[28,27,20,17,11,6]

//=====
   int helper0(vector<int>& nums) {
        vector<int> f;
        vector<int> b;
        int res = -1;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            f.push_back(sum);
        }
        sum = 0;
        for(int i=nums.size()-1; i>=0; i--){
            sum +=nums[i];
            b.insert(b.begin(),sum);
        }
        for(int i=0;i<nums.size();i++){
            if(f[i]==b[i]){
                res = i;
                break;
            }
        }
        return res;
    }
int helper1(vector<int>& nums) {
//    vector<int> f;
    vector<int> b;
    int res = -1;
    int sum =0;

    for(int i=nums.size()-1;i>=0;i--){
        sum+=nums[i];
        b.insert(b.begin(),sum);
    }
    sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum==b[i]){
            res = i;
            break;
        }
    }
    return res;
}

//===
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

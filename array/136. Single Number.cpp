//===類似題===
137. Single Number II
311. Sparse Matrix Multiplication
1521. Find a Value of a Mysterious Function Closest to Target
2234. Maximum Total Beauty of the Gardens
//===思路===

//====
int helper1(vector<int>& nums){
        int res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i+=2){
            if(i==(n-1)) {
               res = nums[n-1];
               break;     
            } 
            if(nums[i]!=nums[i+1]){
                res = nums[i];
                break;
            }     
        }
        return res;
    }
//===思路2===

//=====
int helper0(vector<int>& nums){
        unordered_map<int,int> m;
        int res =0;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto a:m){
            if(a.second==1) {
                res=a.first;
                break;
            } 
        }
        return res;
    }
    int singleNumber(vector<int>& nums) {
        return helper1(nums);
//        return helper0(nums);
    }

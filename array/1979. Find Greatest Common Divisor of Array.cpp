//===類似題====
1980. Find Unique Binary String
1819. Number of Different Subsequences GCDs
1952. Three Divisors
2413. Smallest Even Multiple
//===思路===

//=======
int helper0(int x, int y){
        while(y!=0){
            int t =y; 
            y=x%y;
            x=t;
        }
        return x;
}
int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return helper0(nums[0],nums[nums.size()-1]);
}

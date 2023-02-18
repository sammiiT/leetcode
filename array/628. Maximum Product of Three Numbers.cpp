//===類似題===
629. K Inverse Pairs Array
1385. Find the Distance Value Between Two Arrays
807. Max Increase to Keep City Skyline
2433. Find The Original Array of Prefix Xor
//===思路===

//====
int maximumProduct(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    res = nums[0]*nums[1]*nums[n-1];
    res = max(res, nums[n-3]*nums[n-2]*nums[n-1] );
    return res;
}

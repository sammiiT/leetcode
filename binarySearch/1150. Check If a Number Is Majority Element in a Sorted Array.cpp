//=== more challenge ===

//=== 思路 ===
(*) 用binary_search找到 target的左邊index 和 右邊index
左右兩邊index相減可得到個數, 再與nums.size()/2相比 即可判斷

bool isMajorityElement(vector<int> &nums, int target) {
    int l,r;
    l = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    r = upper_bound(nums.begin(),nums.end(),target)-nums.begin();    
    return (r-l>nums.size()/2);
}

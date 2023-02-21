//===類似題===
2100. Find Good Days to Rob the Bank
1005. Maximize Sum Of Array After K Negations
1356. Sort Integers by The Number of 1 Bits
2163. Minimum Difference in Sums After Removal of Elements
//===思路===
(*)本題說是找出sequence, 但sequence要按照原陣列的排列順序
1.先將陣列copy並重新排列,descending;
2.利用unordered_map<int,int> 紀錄k個最大的值
3.遍歷原陣列,並查看是否出現在map中, 如果出現在map中, 則push_back到vector中;這樣sequence就會依照原陣列的順序

//===
vector<int> helper1(vector<int>& nums, int k){
    vector<int> t = nums;
    unordered_map<int,int> m;
    vector<int> res;
    sort(rbegin(t),end(t));
    for(int i=0;i<k;i++){  m[t[i]]++; }
    for(int i=0;i<nums.size();i++){
        if(m[nums[i]]-->0) res.push_back(nums[i]);
    }
    return res;
}    

vector<int> maxSubsequence(vector<int>& nums, int k) {
    return helper1(nums,k);
}

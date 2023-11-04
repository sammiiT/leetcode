//===類似題===
2401. Longest Nice Subarray
2537. Count the Number of Good Subarrays
//===思路===
(*)遍歷數列 
1. 位置索引 i,j; i是distinct subarray的開頭, j是disctinct subarray的尾
2.將出現過的數值,記錄到map<int,int>中; <數值,位置>
3.如果出現相同(duplicate)的數值,則移動i到 (duplicate位置+1)
3-1. 移動時, 將每一個數從累加sum中減去, 並將數值從ump中erase

ex:
舊   i       j
    [3   2   3   1]
新       i = ump[nums[j]]+1    
         ump.erase(nums[i])
         sum = sum-nums[i]


ex:
舊   i                   j 
    [4   2   3   8   7   3   1]
新               i = ump[nums[j]]+1    
                 ump.erase(nums[i]); 會earse 0,1,2
                 sum = sum-nums[i]; 會減去 [0],[1],[2]

long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> ump;
    long long res = 0;
    long long sum = 0;
    int i=0,j=0, n = nums.size();
    while(j<n){
        if((j-i+1)<=k){
            if(ump.count(nums[j])){
                for(;i<ump[nums[j]]+1;++i) {
                    sum-=nums[i];
                    ump.erase(nums[i]);
                }
                ump[nums[j]]=j;
                sum = sum + nums[j];        
             }else{
                ump[nums[j]] = j;
                sum = sum+nums[j];       
             }
         }else{
            sum = sum-nums[i];
            ump.erase(nums[i]);
            ++i;
            if(ump.count(nums[j])){
                for(; i<ump[nums[j]]+1; ++i) {
                    sum-=nums[i];
                    ump.erase(nums[i]);
                }
                ump[nums[j]]=j;
                sum = sum + nums[j];
            }else{
                ump[nums[j]]=j;
                sum = sum + nums[j];
            }        
        }
        if(ump.size()==k) { res = max(res,sum); }
        ++j;
    }
    return res;
}

//===寫法2===
(*) sliding window概念
(*) unordered_map.size() 會以key的數量為準

long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> ump;
    int res = 0;
    int sum = 0;
    for(int i=0, j=0; j<nums.size(); ++j){
        ump[nums[j]]++;
        sum+=nums[j];
        if((j-i+1)>=k){//sliding window
            if(ump.size()==k) res = max(res,sum);
            ump[nums[i]]--;
            if(!ump[nums[i]]) ump.erase(nums[i]);
            sum-=nums[i];
            ++i;
        }
    }
    return res;
}


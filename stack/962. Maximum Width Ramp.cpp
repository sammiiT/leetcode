//===類似題====
963. Minimum Area Rectangle II
1526. Minimum Number of Increments on Subarrays to Form a Target Array
1255. Maximum Score Words Formed by Letters
312. Burst Balloons

//===思路====


//===========
int maxWidthRamp(vector<int>& nums) {
    int res = 0;
    vector<int> stk;//stack<int> stk;
    
    for(int i=0;i<nums.size();i++){
        //if(stk.empty()||stk.back()>nums[i]){
        if(stk.empty()||nums[stk.back()]>nums[i]){
            stk.push_back(i);
        }else{
            int l = 0, r = stk.size()-1;
            while(l<r){
                int m = l+(r-l)/2;
                if(nums[stk[m]]>nums[i]) l=m+1;
                else// nums[stk[m]]<=nums[i]
                    r = m;
            }
            res = max(res,i-stk[r]);
        }
    }
    return res;
}

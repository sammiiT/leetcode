//===類似題====
963. Minimum Area Rectangle II
1526. Minimum Number of Increments on Subarrays to Form a Target Array
1255. Maximum Score Words Formed by Letters
312. Burst Balloons

//===思路====
(*)stack資料結構求解; 紀錄decreasing stack
- decreasing定義: nums[i]的decreasing, 但在stack中以index "i"做紀錄
   

        |
        +-+
        | |-+ +-+
        | | | | |
        | | | | | 
        | | |-+ |
        | | | | |
    ----------------    
index    0 3 7 9   

-當index_9的value 大於decreading stack的top(), 此top對應nums數列中的index_7
-對decreasing stack做binary_search, 找到第一個小於等於nums[i]的數,即為一次解
-對每次的解做max(x,y)運算;最大的那一個即為解

0,3,7做binary_search逼近; 最後(l==r)時,停在index_3的位置
- 9-3 = 6 ; 即為Ramp其中一解    


    
    
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

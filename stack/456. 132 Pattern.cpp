//===類似題===
1. Two Sum
1705. Maximum Number of Eaten Apples
2141. Maximum Running Time of N Computers
1762. Buildings With an Ocean View

//===思路===
(*)利用stack<int>資料結構
(*)從後往前遍歷
-nums[i]>stk.top()
-紀錄被pop的數值, 將與下一個nums[i]做比較
-接下來nums[i]若小於紀錄的數, 則存在132pattern

(*)三個數,某數小於第二小的數, 此數必定小於最大的那一個數
  
//====
bool helper0(vector<int>& nums) {
    stack<int> stk;
    int rec = INT_MIN;
    for(int i=nums.size()-1; i>=0; --i){
        if(rec>nums[i]) return true;//nums[i]<rec 一定小於stk.top(),連續小於兩個
        while(!stk.empty() && stk.top()<nums[i]){
            rec = stk.top();;
            stk.pop();
        }
        stk.push(nums[i]);
    }
    return false;
}

bool find132pattern(vector<int>& nums) {
    return helper0(nums);
}
//====faile
(*)由前往後遍歷, 會錯誤
Input
      nums = [3,1,4,2]
Output    
      false
Expected
      true
(*)4會把1和3 pop, 被紀錄的數值為 3
(*)經比較 1,4,2會沒有考慮到, 因為1沒有被記錄到  
bool helper1(vector<int>& nums) {
    stack<int> stk;
    int rec=INT_MAX;
    for(int i=0;i<nums.size();++i){
        if(rec<nums[i] && !stk.empty() && stk.top()>nums[i]) return true;//
        while(!stk.empty()&& stk.top()<nums[i]){
            rec = stk.top();stk.pop();
        }
        stk.push(nums[i]);
    }
    return false;
}    



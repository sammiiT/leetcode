//===類似題===
1005. Maximize Sum Of Array After K Negations
340. Longest Substring with At Most K Distinct Characters
424. Longest Repeating Character Replacement
487. Max Consecutive Ones II

//===思路===
(*)sliding window求解
1.遍歷數列
2.兩指標, r=window_right,l=window_left
3.移動r, 當遇到"0",則k-1:
當substring的"0"個數超過k時, 要開始移動l(window_left)
  
4.開始移動l, 當遇到"0", 則k+1;移動到k==0時跳出window_left迴圈
  
//====
int helper0(vector<int>& nums, int k){
    int r=0,l=0;
    int n=nums.size();
    int res = 0;
    
    for(r=0; r<n; r++){
        k=k-(nums[r]==0);
        if(k>=0) res = max(res,r-l+1);
        while(k<0){
            k=k+(nums[l]==0);
            ++l;//最後會跳過前面的'0'
        }
    }
    return  res;
}

int longestOnes(vector<int>& nums, int k) {
  return helper0(nums,k);
}

//===思路2====
(*) sliding window
(*) for(int j=-1,i=0;i<nums.size();++i) 
- i是陣列中的每一個index
- j是前一個
  
(*)當 nums[i]==0
- k>0 對k--;  
- k==0 對j做運算, 直到下一個nums[j]==0時停止
-- 前面的0 排除, 後面的0新加進去  
      j     i  => res = max(res,j-j); 
      V     v 
1,1,1,0,1,1,0,1

//=============  
int longestOnes(vector<int>& nums, int k){
    int res = 0;
    for(int j=-1, i=0; i<nums.size(); ++i){
        if(nums[i]==0){
            if(k) --k;
            else{
                do{ ++j;
                } while(nums[j]);
            }
        }
        res = max(res,i-j);
    }
    return res;
}




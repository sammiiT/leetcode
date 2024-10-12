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
        while(k<0){//k為負值,才會進入, 直到跳過前面的0,讓k==0
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
//===思路3===
(*)sliding window
int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int left = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0) --k;
            while(k<0){//if(k<0){
                k+=(nums[left++]==0);
            }
            res = max(res,i-left+1);
        }
        return res;
}

//===思路4===
(*) queue + sliding_window
1.建立queue<int>,紀錄出現0的index, 較小的index會放在queue的前端
- queue的size就是k:可以更改為"1"的"0"個數
-遍歷數列, 如果出現0則 push到queue, 直到(queue.size==k)再做計算  
-當(queue.size==0), 將queue做pop, 其內容為第一個"0"的index; 代表consecutive 1的長度從此index截斷, 要重新計算

      0 1 2 3 4 5 6 7 8        0 1 2 3 4 5 6 7 8    
nums  1,0,0,1,1,0,1,1,1    =>  1,0,0,1,1,0,1,1,1                  
k=2      \ \                      \       \  
          | q.push(2)              |       q.push(5) 
        q.push(1)                  q.pop(): 從index1截斷, 長度從index2重新計算

- 如果k=0時; 必須多一個q.empty()判斷;因為"空"做pop會有異常操作

- 宣告變數i,j; i為consecutive_1的尾, j為consecutive_1的頭

  
int longestOnes(vector<int>& nums, int k){
    queue<int> q;
    int i=0,j=0,res=0;
    for(i=0,j=0; i<nums.size(); ++i){
        if(nums[i]==0){
          int f = i;
          if(q.size()<k){
              q.push(i);
          } else {//q.size()==k
              if(!q.empty()){//如果k==0條件, 會發生此結果
                  f = q.front();
                  q.pop();
                  q.push(i);
              }
              j = f+1;//重新紀錄conscutive_1的頭
          }
         }
        res = max(res,i-j+1);    
    }
    return res;
}

//=== 思路5===
(*) 利用queue<int> 
(*) sliding window 技巧 --> 先完成正常情況下的程式碼,再構思遇到boundary condition情況下的運算
int longestOnes(vector<int>& nums, int k) {
    int i=0,j=0,n=nums.size();
    queue<int> q;
    
    int res = 0;
    int count =0;
    
    for(; i<n; ++i){
        if(nums[i]==0) {
            count++;
            q.push(i);
        }
        while(count>k){
            j = q.front()+1;
            q.pop();
            count--;
        }
        res = max(res,i-j+1);
    }   
    return res;
}

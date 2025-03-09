//===類似題====
689. Maximum Sum of 3 Non-Overlapping Subarrays
1638. Count Substrings That Differ by One Character
1067. Digit Count in Range
336. Palindrome Pairs

//===思路=====
(*) 累加陣列:
  0      1          2              3                  4                    5                     6
[[0], [0]+[1], [0]+[1]+[2], [0]+[1]+[2]+[3], [0]+[1]+[2]+[3]+[4], [0]+[1]+[2]+[3]+[4]+[5], [0]+[1]+[2]+[3]+[4]+[5]+[6]]
-0-index, 
[i:j]的總和 => [j]-(i==0)?0:[i-1]//[j]-[i-1] (i>0)
[0:3]總和 => [3]-(i==0)?0:[i-1]       or   [3]-[0]+nums[0]  
[1:3]總和 => [3]-[0]                  or   [3]-[1]+nums[1]
[2:6]總和 => [6]-[1]                  or   [6]-[2]+nums[2] 
[i:j]總和 => [j]-[i-1]                or   [j]-[i]+nums[i]

(*)
-遍歷的過程中會記錄"極限值"
-"極限值" 會跟接下來遍歷過程中的數值做比較, 
  
[1:2] [2,3] [3:4]... [n-2:n-1] 
        |
       max ---------+
                     \ 配對
[1:3] [2:4] [3:5]    [n-3:n-1]
                        |
                       max
 
 0 1 2 3 4 5 6 7 8 9 10 11 12 13
[a,b,c,d,e,f,g,h,i,j,k, l, m, n]  "一般陣列"                    
   \ /                   \   / 
    |                      | 
  [1:2]                 [11:13] 
在遍歷的過程中, [1:2]最大,所以會在接下來的計算過程中,都會以此做計算基礎
[11:13]是遍歷到最後發生的最大值  
  
  
(*)初始值定義: 假設是"累加陣列"
[a,b,c,d,e,f,g,h,i,j,k, l, m, n]
 |-|  firstLen
 |---| secondLen
 |-------| firstLen+secondLen

|------| firstLen+secondLen 可區分為兩種情況
|-||---| firstLen, secondLen  ----情況1 
|---||-| secondLen, firstLen  ----情況2

(*)計算
 0 1 2 3 4 5 6 7 8 9 10 11 12 13
[a,b,c,d,e,f,g,h,i,j,k, l, m, n]
       |       | 
       3       7
i=7 ;first = 2 ;second = 3
fmax = max(fmax, [i-second]-[i-(first+second)])
                   7-3=4      7-5=2
 [i:j]總和 => [j]-[i-1] 
 [3:4]總和 => [4]-[2]      
 
smax = max(smax,[i-fisrt]-[i-(first+second)])  
 [3:5]總和 => [4]-[2]      

比較:情況1和情況2 ; "fmax, smax有可能是之前得到的maximum"
max(fmax+nums[i]-nums[i-second]),(smax+nums[i]-nums[i-first])
     |    \__________________/      |    \______________/
     |           |                  |            |
 有first   剩下second要加總      有second    剩下first要加總
  
//=======
int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    int n = nums.size();
    int fmax;
    int smax;
    int res;
    for(int i=1;i<n;++i){ nums[i]=nums[i-1]+nums[i]; }

    res = nums[firstLen+secondLen-1];
    fmax = nums[firstLen-1];
    smax = nums[secondLen-1];

    for(int i=firstLen+secondLen; i<n; ++i){
        fmax = max(fmax,nums[i-secondLen]-nums[i-(firstLen+secondLen)]);
        smax = max(smax,nums[i-firstLen]-nums[i-(firstLen+secondLen)]);
        res = max(res,max(fmax+nums[i]-nums[i-secondLen],smax+nums[i]-nums[i-firstLen]));
    }
    return res;
}

(*)解析
定義區間: 
  總區間: 
  (f+s)區間: 分為 (f+s)或(s+f)
  
    |---f---|-s-|                 |-s-|---f---|
  |---f---|-s-|                 |-s-|---f---|
|---f---|-s-|                 |-s-|---f---|  
|------------------|          |------------------|   



  
fmax = max(fmax,nums[i-secondLen]-nums[i-(firstLen+secondLen)]);
新的區間,以f為開頭做分隔, 並與之前的fmax做比較           
|---f--|-s-|            
     
  
smax = max(smax,nums[i-firstLen]-nums[i-(firstLen+secondLen)]);
新的區間,以s為開頭做分隔, 並與之前的smax做比較           
|-s-|---f---|           
  
res = max(res,max(fmax+nums[i]-nums[i-secondLen],smax+nums[i]-nums[i-firstLen]));
分別以新區間的f為開頭 和s為開頭 做maximum判斷


  

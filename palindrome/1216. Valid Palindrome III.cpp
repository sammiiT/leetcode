//===

//===思路====
(*)DFS概念
- 有點像tree類型中的 maximum_length 和 minimum_length問題
- 建立一 2D-table, 紀錄每一區間的palindrome, 必須刪除的字元數目(最少數目)
- 最後回傳到最常上層的數值,為最小的"刪減個數", 與題意k做比較, 滿足回傳true, 否則回傳false


(*)注釋:
if(memo[start][end]!=(-1)) return memo[start][end];

上層的   (start@,end@)
          |  \____  \_____________
          |        \               \
下層的 (start0,end0) (start1,end1)  (start#,end#)           
        |  \              |
        |    \_______     |
        |             \   | 
再下層 (start%,end%)  (start2,end2)


-(start0,end0)的再下層會與(start1,end1)的再下層"節點相同"; (start2,end2)
-(start2,end2)在DFS運算中, 會在以(start0,end0)的root中先被運算到, 所以當運算到(start1,end1)時, 往再下層運算時, (start2,end2)已經被運算過了,所以直接回傳
if(memo[start][end]!=(-1)) return memo[start][end];


int helper(string& s, int start, int end, vector<vector<int>>& memo){
    if(start>=end) return 0;
    if(memo[start][end]!=-1) return memo[start][end];//注釋
    
    int res;
    if(s[start]==s[end]){
      res = helper(s,start+1,end-1,memo);
    } else {//s[start]!=s[end]
        res = min(helper(s,start+1,end,memo),helper(s,start,end-1,memo));      
    }
    memo[start][end] = res;
    return res;
}

bool isValidPalindrome(string& s, int k){
    vector<vector<int>> memo(s.size(),vector<int>(s.size(),-1));
    return (helper(s,0,s.size()-1,memo) <=k);
}

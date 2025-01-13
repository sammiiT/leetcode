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
        res = 1 + min(helper(s,start+1,end,memo),helper(s,start,end-1,memo)); //加1是累計刪除的次數
//      res = min(1 + helper(s,start+1,end,memo),  1 + helper(s,start,end-1,memo));              
    }
    memo[start][end] = res;
    return res;
}

bool isValidPalindrome(string& s, int k){
    vector<vector<int>> memo(s.size(),vector<int>(s.size(),-1));
    return (helper(s,0,s.size()-1,memo) <=k);
}

//===寫法2 ===
bool dfs(string& s, int k, int x, int y, vector<vector<int>>& mem){
    if(k<0) return false;
    if(x==y||x==(y-1)) return true;
    if(mem[x][y]!=-1) return mem[x][y];
    
    while(x<y){
        if(s[x]==s[y]){ 
            mem[x][y]=true;
            x+=1;
            y-=1;
        } else {//(s[x]!=s[y])   
            //if(dfs(s, k-1, x+1, y, mem)||dfs(s, k-1, x, y-1, mem)) {mem[x][y]=true; return true;}        
            if(dfs(s, k-1, x+1, y, mem)) { 
                mem[x][y]=true;
                return true;
            } else if(dfs(s, k-1, x, y-1, mem)) { 
                mem[x][y]=true;          
                return true;
            } else {
                mem[x][y]=false;
                return false;
            }
        }
    }
    return true;
}
bool isValidPalindrome(string s, int k) {
    vector<vector<int>> mem(s.size(),vector<int>(s.size(),-1));
    return dfs(s,k,0,s.size()-1,mem);
}


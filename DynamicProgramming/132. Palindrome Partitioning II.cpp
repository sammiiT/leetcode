//=== more challange ===
1745. Palindrome Partitioning IV
2472. Maximum Number of Non-overlapping Palindrome Substrings
2518. Number of Great Partitions
//=== 思路 ====
(1)判斷[i~j]是否為palindrome; 圖解分析判斷式
- 從最短的 palindrome開始分析, 最短palindrome為"2" ; 第一次遍歷長度為2的palindrome;若是palindrome;則valid[i][j]=1
string = [a , b , c , d, e , f , g]
         [a , b]
             [b , c] 
                       ...  [f , g]

- 當判斷palindrome的長度為"4"
string = [a , b , c , d , e , f , g]
         [a , b , c , d]     
             [b , c , d , e]  
                  ...[d , e , f , g]                           

當長度超過2時,會以之前較小長度的palindrome, 做往較長palindrome的判斷依據;  因為之前的較小長度的palindrome已經有判斷紀錄;如:
[a , b , c , d] 是否為palindrome會依據之前 [b,c] 
    [b , c]  
        \
         會依據[b , c]是否為palindorme, 來決定 [a , b , c , d]是否為palindrome
  
所以定義valid[i][j]; (i~j是否為palindrome)可用如下判斷式:
for(int l=2; l<=n; ++l){ //從最短長度2判斷開始
  for(int i=0,j=i+l-1; j<n; ++i,++j){//紀錄每一個長度是否為palindrome
    valid[i][j] = (s[i]==s[j]) && valid[i+1][j-1]; 
                                  //之前較短長度依據
  }
}

(2)有了每一個區間的palindrome判斷依據; 開始做dp update;
-dp[i]: [0~i]區間的最小分段數
-遍歷數列; i從0開始,到(n-1); j從0開始,到(i-1); 如下圖 
for(int i=0; i<n; ++i)
  for(int j=0; i<i; ++j)

以二維判斷dp作圖為,左下運算; dp運算解釋,參考程式說明
  a  b  c  d  e  f
a o  
b o  o    
c o  o  o
d o  o  o  o
e o  o  o  o  o
f o  o  o  o  o  o


int minCut(string s) {
    int n = s.size();
    vector<vector<int>> valid(n,vector<int>(n,1));//判斷[i~j]是否為palindrome
    vector<int> dp(n,n);//這邊dp[i]初始值在宣告時定義, dp(n,n)的意義是最多n個cut, 每一個區段都不是palindrome
    
    //(1)initialize,初始值再定義 => 判斷[i][j]是否為palindrome
    for(int l=2; l<=n; ++l) {//長度為2開始判斷, 是否為palindrome
        for(int i=0, j=i+l-1; j<n;++i,++j){ // 長度為l時,的start為i, end為j
            valid[i][j] = (s[i]==s[j]) && valid[i+1][j-1];
            
        }
    }
    
    //開始計算最小cut
    for(int i=0; i<n; ++i){
        if(valid[0][i]){
            dp[i]=0;//到第i個,都是palindrome,所以不用cut;是0
            continue;
        }
        for(int j=0; j<i; ++j){//前面dp[i],經不是palindrome了,所以從[j+1]判斷
            if(valid[j+1][i]){ //dp[i] 就是 [j~i];其中j等於0
                dp[i]=min(dp[i],dp[j]+1);//dp[j]+1定義: [j+1][i]是palindrome, [j]不是palindrome, 所以要切一刀(1 cut)
            }                            //+1就是那個 one cut
        }
    }
    return dp[n-1];
}

//=====


//===用DFS會Time Limited Exceeded ===
bool isPalindrome(string& s, int left, int right){
    while(left<right){
        if(s[left]!=s[right]) return false;
        left++;right--;
    }
    return true;
}
void helper(string& s,int start, vector<string>& out, int& res){
    if(start>=s.size()){
        res = min(res, (int)out.size()-1);
    }

    for(int i=start; i<s.size(); ++i){
        if(isPalindrome(s,start,i)){
            out.push_back(s.substr(start,i-start+1));
            helper(s,i+1,out,res);
            out.pop_back();
        }
    }
}

    int minCut(string s) {
        int res = s.size()-1;
        vector<string> out;
        helper(s,0,out,res);
        return res;    
    }

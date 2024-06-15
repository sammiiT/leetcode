//===類似題===
1940. Longest Common Subsequence Between Sorted Arrays
583. Delete Operation for Two Strings
1092. Shortest Common Supersequence
2207. Maximize Number of Subsequences in a String
//===思路===
(*)dp[i][j]不能解釋為區間[i:j] ; 不能解釋為區間i到j
=> 要解釋為 text1在[0:i], text2在[0:j]時所產生的字串; 一共有幾個common subsequence

(*)此題為全二維平面計算, 不是"左下", "右上" 平面
for(int i=1;i<m;++i){
    for(int j=1;j<n;++j){

左下平面:
for(int i=0;i<m;++i){
    for(int j=0;j<i; ++j){    

右上平面:
for(int i=0; i<m; ++i){
    for(int j=i; j<n;++j){

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m,vector<int>(n));

    for(int i=0;i<m;++i) dp[i][0]=(i>0&&dp[i-1][0])?1:(text1[i]==text2[0])?1:0;    
    for(int i=0;i<n;++i) dp[0][i]=(i>0&&dp[0][i-1])?1:(text1[0]==text2[i])?1:0; 
    
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(text1[i]==text2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

//===寫法2====
(*)
(*) text1[i-1]==text2[j-1]
- 用(i-1),(j-1)目的是因為, 可以從0,0開始
- dp[i][j]的結果是儲存前一個結果的值; 前一個結果為[i-1][j], [i][j-1], [i-1][j-1]
- dp的最後一個位置的值, dp[m][n] 就是"解"
- dp[i][j]=1+dp[i-1][j-1]; //其中1就是 (i-1,j-1)位置的個別結果...wrong?
                           其中1就是 (text1[i-1]==text2[j-1])的結果, 再加上(i-1,j-1)之前的結果

(*)
dp[1][1] = 1+dp[0][0], 位置(1,1)儲存了(0,0)的結果
如果dp[0][0]要直接儲存(0,0)的結果, 必須先將此邊界條件定義好
用[i-1][j-1], 可以在運算中, 計算出對應的邊界條件;邊界條件[0][0]是在運算過程中儲存在[1][1]位置

dp[4][6]=1+dp[3][5] ; 其中+1是 [3][5]兩個位置的字元相等, 所以加一
dp[5][7]=1+dp[4][6]

(*)圖解
     ___ dp[0] = dp[0-1] => 沒有(-1)索引, 要自己先定義; 宣告dp時定義, 在運算時定義   
    |    dp[0][0]要自己定義; 藉此可以定義如下 
    |    dp[0][j]=dp[0][j-1] ; (i=0,j>1); 雖然可以定義s2[j-1],但沒辦法從原自串定義 s1[0-1]的情況; 所以dp[0][j]定義為"0" 
    |    dp[i][0]=dp[i-1][0] ; (i>1,j=0); 雖然可以定義s1[i-1],但沒辦法從原自串定義 s2[0-1]的情況; 所以dp[i][0]定義為"0"
    |                                                     ???無法解釋 wildcard matching的算式???             
    |    __ dp[1] = f(1-1); dp[1]是儲存index (1-1)的結果 
    |  /      
    | | 
    0 1 2 3 4 5 6 7 8 9   => dp_index         
    C B A B C A B C C
0 A 0 0 1 1 1 1 1 1 1 
1 B 0 1 
2 C 1
3 A 1
4 B 1
5 C 1
6 B 1
7 A 1
8
dp[1][1] => (s1[1-1]==s2[1-1])?

s1[1] s2[1]
=>s1[2-1] s2[2-1]
=>dp[2][2]

(*)圖解2
        0 1 2 3 4 5 6 7 8   => 原string index
      0 1 2 3 4 5 6 7 8 9   => dp_index         
      @ C B A B C A B C C
  0 @   0 0 0 0 0 0 0 0 0 
0 1 A 0 0 0 1 1 1 1 1 1 1  
1 2 B 0 0 1 1 2 2 2 2 2 2
2 3 C 0 1 1 1 2 3 3 3 3 3 
3 4 A 0 1 1 2 2 3 4 4 4 4
4 5 B 0 1 2 2 3 3 4 5 5 5
5 6 C 0 
6 7 B 0
7 8 A 0
| |
|  \__ dp_index
|
 \__ 原string index


int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();//8
        int n = text2.size();//7
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];        
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }        
            }
        }
        return dp[m][n];//dp[(m+1)-1][(n+1)-1];
    }

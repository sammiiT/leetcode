//===類似題===
393. UTF-8 Validation
792. Number of Matching Subsequences
1055. Shortest Way to Form String
2486. Append Characters to String to Make Subsequence

//===思路1===
(*)動態規劃 dynamic programming
//====
bool isSubsequence(string s, string t){
    int m = s.size();
    int n = t.size();
    
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    
    for(int i=1; i<=m; i++){
        for(int j=1;j<=n;j++){//直接平移一個單位,初始值從[0][0]開始
            if(s[i-1]==t[j-1]) dp[i][j]= dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return (dp[m][n]==m);//最後算完查看是否等於s的size();
}

//===思路2===
(*)遍歷較長數列 t
- 比較數列元素 s[i]與t[j]是否相等, 如果相等則i進一位
- 遍歷完t,判斷i是否等於數列s的size()
--s[i]==t[j] =>i++ ,最後的index會剛好等於 s.size()    
    
//===
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i=0;
        for(int j=0; j<t.size() && i<s.size(); ++j){
            if(s[i]==t[j]) ++i;
        }
        
        return (i==s.size());
    }
};

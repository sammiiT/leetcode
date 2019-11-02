class Solution {
public:
    string longestPalindrome(string s) {
        // vector<vector<int>> dp; how initialize        
        if(s.empty()) return "";
/*
    dp[i][j]:記錄從第j個到第i個是否為 回文
    left:回文初始點
    right:回文終點
    len:回文長度
*/
        int dp[s.size()][s.size()] = {0}, left = 0,right = 0, len=0;
        
        for(int i=0; i<s.size(); ++i){
            dp[i][i]=1;
/* 5個元素
dp[0][4] =>dp[j+1][i-1]=dp[1][3]:s[0]==s[4]則檢查,dp[1][3]是否回文
dp[1][4] =>dp[j+1][i-1]=dp[2][3]:
dp[2][4] =>dp[j+1][i-1]=dp[3][3]:
dp[3][4] =>dp[j+1][i-1]=dp[4][3]:用到 i-j<2,間距為1(相鄰)的情況
*/
            
            for(int j=0; j<i; ++j){
                dp[j][i] = ((s[i]==s[j])&&(i-j<2||dp[j+1][i-1]));
                
                if(dp[j][i]&&len<i-j+1){
                    left = j;
                    right = i;
                    len = i-j+1;
                }
            }
        }
        return s.substr(left,right-left+1);
    }
};
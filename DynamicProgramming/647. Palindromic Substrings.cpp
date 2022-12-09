    int helper1(string s){
        int res = 0;
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));

        for(int i=n-1; i>=0; i--){
            dp[i][i]=1;
            for(int j=i+1; j<n; j++){
                dp[i][j]=(s[i]==s[j]) && (j-i<=2 || (dp[i+1][j-1])); 
                if(dp[i][j]) res++;
            }        
        }
        for(int i=0; i<n; i++){//計算單一
            res++;
        }
        return res;
    }

    int helper0(string s){
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int res = 0;

        for(int i=n-1; i>=0; i--){
            //dp[i][i]=1;
            for(int j=i; j<n; j++){//從相鄰兩個位址開始, i,(j=i+1)  
                dp[i][j]=(s[i]==s[j])&&((j-i<=2) || dp[i+1][j-1]);    
/*
dp[3][3]
dp[i][j]=(s[i]==s[j]) && (dp[i+1][j-1] ||(j-i<=2) );//會錯誤
原因:
當i=3, j=3 且s[i]==s[j]
此時 dp[i+1][j-1]=dp[4][2]會在範圍之外=>heap-buffer-overflow 
所以在前面加上 j-i<=2 =>有三個element =>如果是palindrome, 三個一定是滿足palindrome
*/                
//                
                if(dp[i][j]) res++;
            }
        }
        return res;
    }

    int countSubstrings(string s) {
        return helper1(s);
//        return helper0(s);
    }

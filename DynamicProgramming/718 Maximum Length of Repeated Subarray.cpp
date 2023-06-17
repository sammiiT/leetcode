//===類似題====


//===思路====

//=====
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        int res = 0;
                            //A as row,  B as column
        vector<vector<int>> dp(sizeA,vector<int>(sizeB,0));
        
        for(int i=0; i<sizeA; ++i) dp[i][0]=(A[i]==B[0])?1:0;
        for(int i=0; i<sizeB; ++i) dp[0][i]=(A[0]==B[i])?1:0;
            
        
        for(int i=1;i<sizeA;++i){
            for(int j=1;j<sizeB;++j){
                if(B[j]==A[i]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=0;
                
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
};

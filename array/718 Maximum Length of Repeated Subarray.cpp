//===類似題===
1567. Maximum Length of Subarray With Positive Product
1923. Longest Common Subpath

//===思路===
(*)以對應點(i,j)來看,
 
  [0]  [1][2][3] [4] [5] 
   7    4  2  2   1   3
         /   /   
    +--+   /
   /     / 
  2    2  1   3   4   5 
 [0] [1] [2] [3] [4] [5]
 
關係式:
dp[i][j]=dp[i-1][j-1]+1
 
(*)
dp[i][j]: 第一數列的 i_index 和 第二數列的 j_index
(nums1[i]==nums2[j])  對應點(i,j)相等, 所以加1
(nums1[1]==nums2[3])  對應點(1,3)相等, 所以加1
 
(*)
dp[i-1][j-1] 比較前一個對應點(i-1,j-1)的數值
dp[1][3]=dp[1-1][3-1]+1
         =dp[0][2] + 1                

(0,2):前一個對應點的數值 
 +1  :(1,3)對應點相等, 所以+1

(*)每一個數列的index都要遍歷另一數列的點,一次 => 因為有可能發生數列後面與 數列前面相等
for(int i=1; i<nums1.size(); ++i){
    for(int j = 1; j<nums2.size(); ++j{
    }
}

7,4,2,2,1,3   => 遍歷到index=2開始與另一數列 index=0   
2,2,1,3,4,5   => index=0開始

//===
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        int res = 0;
                            //A as row,  B as column
        vector<vector<int>> dp(sizeA,vector<int>(sizeB,0));
        
        for(int i=0; i<sizeA; ++i)//計算dp起始值,比需順便將 maximum length考慮進去,不然會錯誤 
          res = max(dp[i][0]=(A[i]==B[0])?1:0,res);
        for(int i=0; i<sizeB; ++i) 
          res = max(dp[0][i]=(A[0]==B[i])?1:0,res);
          
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

//===類似題===
833. Find And Replace in String
2518. Number of Great Partitions
2248. Intersection of Multiple Arrays
1806. Minimum Number of Operations to Reinitialize a Permutation
//===思路===
(*)vector<vector<int>> res(m,{});//錯誤宣告; 宣告必須明確,不能用{}
res.push_back({});//執行過程不用像宣告這麼明確定義
//=====
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> res(m);
        for(int i=0; i<m; ++i){
            for(int j=A[0].size()-1; j>=0; --j){//flip
                res[i].push_back(!A[i][j]);//invert   
            }
        }
        return res;
        
    }
    //(1)flip: horizontal flip
    //(2)
};

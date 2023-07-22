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
};
//===思路2===
(*)兩個對稱點做swap

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int m = image.size();
    int n = image[0].size();

    for(int i=0;i<m;++i){
        int l = 0, r = n-1;
        while(l<r){
            int t = image[i][l];
            image[i][l]=!image[i][r];
            image[i][r]=!t;
            l++;
            r--;
        }
        if(l==r) image[i][l]=!image[i][l];
    }
    return image;
}

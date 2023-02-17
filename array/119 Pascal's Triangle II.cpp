//===類似題===
120. Triangle
2221. Find Triangular Sum of an Array
//===思路===
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,0);
        res[0]=1;
        
        for(int i=1; i<=rowIndex; ++i){
            for(int j=i;j>=1;--j){
                res[j]=res[j-1]+res[j];
            }         
        }
        return res;
    }
};

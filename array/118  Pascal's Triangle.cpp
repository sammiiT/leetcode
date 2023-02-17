//===類似題===
119. Pascal's Triangle II
1411. Number of Ways to Paint N × 3 Grid
1314. Matrix Block Sum
1879. Minimum XOR Sum of Two Arrays
//===思路===

//=========
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> res;
        
        for(int i=1; i<=numRows; ++i){
            vector<int> tmp;
            for(int j=1; j<=i; ++j){
                if(j==1||j==i){
                    tmp.push_back(1);
                }else{
                    vector<int> t = res.back();
                    tmp.push_back(t[j-1]+t[j-2]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

//===思路2===
vector<vector<int>> generate(int numRows){
    vector<vector<int>> res;
    for(int i=0;i<numRows;i++){
        res[i].resize(i+1,1);
        for(int j=1; i<i; j++){
            res[i][j]=res[i-1][j-1]+res[i-1][j];
        }
    }
    return res;
}


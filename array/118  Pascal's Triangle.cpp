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
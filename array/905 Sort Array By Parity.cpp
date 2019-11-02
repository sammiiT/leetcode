class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        
        for(int i=0;i<A.size();++i){
            if(A[i]%2){//g
                res.push_back(A[i]);
            }else{//o
                res.insert(res.begin(),A[i]);
            }
        }
        return res;
    }
};
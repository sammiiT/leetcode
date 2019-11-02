class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> g;
        vector<int> o;
        vector<int> res;
        
        for(int i=0;i<A.size();++i){
            if(A[i]%2){//g
                g.push_back(A[i]);
            }else{//o
                o.push_back(A[i]);
            }
        }
        
        for(int i=0; i<A.size()/2; ++i){
            res.push_back(o[i]);
            res.push_back(g[i]);
        }
        return res;
        
    }
    
    vector<int> sortArrayByParityII_OK(vector<int>& A) {
        
        vector<int> even;
        vector<int> odd;
        vector<int> res;
        
        for(int i=0; i<A.size(); ++i){
            if(A[i]%2){//奇數
                odd.push_back(A[i]);
            }else{//偶數
                even.push_back(A[i]);
            }
        }
        
        int o=0,e=0;
        for(int i=0; i<A.size(); ++i){
            
            if(i%2){
                res.push_back(odd[o]);
                o++;
            }else{
                res.push_back(even[e]);
                e++;
            }
            
        }
        return res;
    }
};
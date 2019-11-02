class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int n=S.size();
        int count = 1;
        
        for(int i=1; i<=n; ++i){
            if(i<n&&S[i]==S[i-1]){
                count+=1;
            }else{
                if(count>=3){
                    vector<int> tmp(2,0);
                    tmp[0] = i-count;
                    tmp[1] = i-1;
                    res.push_back(tmp);
                }
                count=1;
            }
        }
        return res;
    }
    
    vector<vector<int>> largeGroupPositions_OK(string S) {
        int cnt;
        vector<vector<int>> res;
        
        cnt=1;
        for(int i=1; i<=S.size(); ++i){
            if(i<S.size() && S[i]==S[i-1]){
                cnt++;
            }else{//S[i]!=S[i-1]
                if(cnt>=3){
                    vector<int> out(2,0);
                    out[0]= i-cnt;
                    out[1]= i-1;
                    res.push_back(out);
                }
                cnt=1;
            }
        }
        return res;
    }
};

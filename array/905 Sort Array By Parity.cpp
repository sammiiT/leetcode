//===類似題===
906. Super Palindromes
2164. Sort Even and Odd Indices Independently
//===思路===
1.遍歷數列
-奇數用push_back放到陣列後方
-偶數用insert放到陣列前方
//===
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
//===寫法2===
vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> even;
    vector<int> odd;
        
    for(int i:nums){
        if(i%2) odd.push_back(i);
        else even.push_back(i);
    }    
    even.insert(even.end(),odd.begin(),odd.end());
    return even;
}

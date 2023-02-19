//===類似題===
831. Masking Personal Information
2138. Divide a String Into Groups of Size k
//===思路===
1.用兩個index來記錄group的頭尾; j=頭, i=尾
2.當s[i]==s[j],則i際遇往下一個位置移動
3.當s[i]!=s[j], 則將(j~i-1)的substr紀錄; 並更新j的位置; (j=i)
--如果 (j~i-1)<3 則不記錄(題意)
//=====
vector<vector<int>> helper0(string s){
    vector<vector<int>> res;
    int i,j;
    for( j=0,i=0;i<=s.size();i++){
        if((i==s.size())||(s[i]!=s[j])){
            string str = s.substr(j,i-j);
            if(str.size()>=3){
                res.push_back({j,i-1});
            }
            j=i;
        }
    }
    return res;
}

vector<vector<int>> largeGroupPositions(string s) {
    return helper0(s);    
}

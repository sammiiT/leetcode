//===類似題====
1447. Simplified Fractions
2229. Check if an Array Is Consecutive
1759. Count Number of Homogenous Substrings
2213. Longest Substring of One Repeating Character

//===思路====
(*)有點像sliding window的作法
1.遍歷比較位址i和源頭j是否不相等
2.若不相等, 則(i-j)紀錄有重複多少個一樣的字元(character),並比較求maximum
3.要多加一個bounadary在string末端, 因為若最後一串substring沒有相異的字元,沒辦法觸發紀錄字串長度  
//====
int helper1(string s){
    int res = 0;
    int i=0,j=0;
    s += "#";
    for(;i<s.size();i++){
        if(s[i]==s[j]) continue;
        res = max(res,(i-j));
        j=i;
    }
    return res;
}    
//=====
int helper0(string t){
        int res = 0;
        string s = t+'#';//for boundary
        for(int i=0,j=0;i<s.size();i++){
            if(s[i]!=s[j]){
                res = max(res,i-j);    
                j=i;
            }
        }
        return res;
}
int maxPower(string s) {
        return helper0(s);
}

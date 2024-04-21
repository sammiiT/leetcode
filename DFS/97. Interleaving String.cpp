//===more challange===
2418. Sort the People
2911. Minimum Changes to Make K Semi-palindromes
1255. Maximum Score Words Formed by Letters
    
//===思路===
(*)DFS
(*)我這個DFS寫法會造成time_limit_exceeded
(*)比較的基準, 以s3為基準...
//從s3為基準做匹配?? 會不會比較好算??


bool helper(string& s3, int start, string s1, string s2){
    if(!s1.size() && !s2.size()) return true;
//
    for(int i=start; i<s3.size(); ++i){
        if((i-start+1<=s1.size()) && s3.substr(start,i-start+1)==s1.substr(0,i-start+1)){
            if(helper(s3, i+1, s1.substr(i-start+1), s2)) return true;
        }        
        if((i-start+1<=s2.size()) && s3.substr(start,i-start+1)==s2.substr(0,i-start+1)){
            if(helper(s3, i+1, s1, s2.substr(i-start+1))) return true;
        }
    }
    return false;
}

bool isInterleave(string s1, string s2, string s3) {
//    unordered_set<string> st;
    if(s1.size()+s2.size()!=s3.size()) return false;
    return helper(s3,0,s1,s2);
}
//==== 修改版本, 可解決time limited exceeded ====
(*)為避免重複計算, 要在helper一開始加入判斷描述
概念如同 1216 Valid Palindrome III

(*)將每一個擷取出的s1和s2片段前, 分別加入 '@','#'以避免重複
-用unordered_set<string> 將所有的錯誤的('@'+s1+'#'+s2)加入倒set中
-錯誤的set不會被重複計算.
-可解決time limited exceeded, 但運算效率還是很慢

bool helper(string& s3, int start, string s1, string s2,unordered_set<string>& st){
    if(!s1.size() && !s2.size()) return true;
    if(st.count('@'+s1+'#'+s2)) return false;

    for(int i=start; i<s3.size(); ++i){
        if((i-start+1<=s1.size()) && s3.substr(start,i-start+1)==s1.substr(0,i-start+1)){
            if(helper(s3, i+1, s1.substr(i-start+1), s2,st)) return true;
        }
        if((i-start+1<=s2.size()) && s3.substr(start,i-start+1)==s2.substr(0,i-start+1)){
            if(helper(s3, i+1, s1, s2.substr(i-start+1),st)) return true;
        }
    }
    st.insert('@'+s1+'#'+s2);   
    return false;
}

bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        unordered_set<string> st;
        return helper(s3,0,s1,s2,st);
}

//===網路上的寫法====
(*)DFS
(*)有加上一個unordered_set<int> 作為判斷重複計算的依據

bool helper(string& s1, int i, string& s2, int j, string& s3, int k, unordered_set<int>& s) {
        int key = i * s3.size() + j;
        if (s.count(key)) return false;
        if (i == s1.size()) return s2.substr(j) == s3.substr(k);
        if (j == s2.size()) return s1.substr(i) == s3.substr(k);
        if ((s1[i] == s3[k] && helper(s1, i + 1, s2, j, s3, k + 1, s)) || 
            (s2[j] == s3[k] && helper(s1, i, s2, j + 1, s3, k + 1, s))) return true;
        s.insert(key);
        return false;
}

bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        unordered_set<int> s;
        return helper(s1, 0, s2, 0, s3, 0, s);
}



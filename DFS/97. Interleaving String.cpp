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
    st.insert('@'+s1+'#'+s2); //記錄在此,是代表 無法形成interleaving string的combination  
    return false;             //因為是false; 如果是true, 就不會記錄在unordered_set中
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

//====寫法3 ===
(*)同上概念
(*)dfs在有"順序性選擇"的條件下, 才可以用memory來解題
(*)如果每次下一層,都從頭開始, 就比較難用memory方式

bool dfs(string& s1, string& s2, string& s3, int x, int y, int k, unordered_set<int>& s){
    
    int key = x*s3.size()+y;
    if(s.count(key)) return false;
    
    if(x==s1.size()) return s2.substr(y)==s3.substr(k);
    if(y==s2.size()) return s1.substr(x)==s3.substr(k);
       
    if(x<s1.size() && s1[x]==s3[k])
        if(dfs(s1,s2,s3, x+1, y, k+1,s)) return true;
    
    if(y<s2.size() && s2[y]==s3[k])
        if(dfs(s1,s2,s3, x, y+1, k+1,s)) return true;
    
    s.insert(key);#記錄在此,是代表 無法形成interleaving string的combination
    return false; #因為是false; 如果是true, 就不會記錄在unordered_set中
}

#===寫法4====
(*)dfs
(*)memory用2d-array
(*)bool dfs() //搜到一個之後,就回傳, => worst_case 搜到O(n)

    
bool dfs(string& s1,string& s2,string& s3,int start1, int start2, int start3, vector<vector<int>>& mem){

    if(start1==s1.size()) 
        return (s2.substr(start2,s2.size()-start2)==s3.substr(start3,s3.size()-start3));
    
    if(start2==s2.size()) 
        return (s1.substr(start1,s1.size()-start1)==s3.substr(start3,s3.size()-start3));
    
    if(mem[start1][start2]!=-1) 
        return mem[start1][start2];
    
    if(start1<s1.size() && s1[start1]==s3[start3]){
        if(dfs(s1, s2, s3, start1+1, start2, start3+1, mem)) {
            mem[start1][start2]=true;
            return true;
        }
    }    
            
    if(start2<s2.size() && s2[start2]==s3[start3]){    
        if(dfs(s1, s2, s3, start1, start2+1, start3+1, mem)) {
            mem[start1][start2]=true;
            return true;
        }
    }
    mem[start1][start2] = false;
    return mem[start1][start2];
}

bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(),n = s2.size();
    vector<vector<int>> mem(m,vector<int>(n,-1));
    return dfs(s1,s2,s3,0,0,0,mem);
}




    

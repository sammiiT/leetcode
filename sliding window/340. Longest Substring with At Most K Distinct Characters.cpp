//===類似題===

//===思路====

//========
int lengthOfLongestSubstringKDistinct(string s, int k){
    unordered_map<char,int> m;//character, count
    int n = s.size();
    int j = 0, res = 0;
    
    for(int i=0; i<n; i++){
        if(m.find(s[i])==m.end()) k=k-1;
        m[s[i]]++;
        
        if(k>=0) res = max(res, i-j);
        
        while(k<0){
            m[s[j]]--;
            if(m[s[j]]==0) m.erase(s[j]);
            
            j++;
            k=m.size();
        }
    }
    return res;
}
//===思路2===





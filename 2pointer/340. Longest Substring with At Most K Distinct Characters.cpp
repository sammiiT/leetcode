//===more challenge ===

//===思路===
(*) 參考 159. Longest Substring with At Most Two Distinct Characters
  
struct cmp{
  bool operator()(pair<int,int>& a,pair<int,int>& b){//<value, last_index>
      return a.second>b.second;
  }  
};
int lengthOfLongestSubstringKDistinct(string s, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    unordered_map<char,int> ump;
    int res = 0;
    int sum = 0;
    
    s.push_back('#');
    for(int i=0; i<s.size(); ++i){
        if(ump.size()>=k && !ump.count(s[i])){
            res = max(res,sum);
            
            for(auto it:ump) pq.push({it.first,it.second});
            
            int last_idx1 = pq.top().second; pq.pop();
            
            sum = i-last_idx1;
            ump.erase(s[last_idx1]);
            ump[s[i]]=i;
            
        } else {
            ump[s[i]]=i;
            sum++;
        }
        
    }    
}


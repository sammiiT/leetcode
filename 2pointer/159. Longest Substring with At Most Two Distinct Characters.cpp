//===more challenge===
//===思路======
(*)
0 1 2 3 4 5 6
c c a a b b b
  |   |   
  |    map[a]=3    
  \
  map[c]=1

遍歷到idx=4,此時map.size()==2
- 重新紀錄長度 (3-1)=2 ;
- {c,1} 從priority_queue pop出去
- 再次重新記錄長度 (2+1) =3; 其中1是 "b"


(*) priority_queue + unordered_map
unordered_map<char,int> //<character, last_index>
-用來紀錄每一個出現過character的最後一個index
-map.size()>=2時, 多加入一個新的character, 要開始計算string長度

priority_queue
-用來記錄每一個character最後出現index, 並依index由小到大排列
  
struct cmp{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second > b.second;
    }  
};

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char,int> ump;//<character, last_index>
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;//<char,last_index>
    int res = 0;
    int sum = 0;
    
    s.push_back('#');
    
    for(int i=0; i<s.size(); ++i){
        if(ump.size()>=2 && !ump.count(s[i])){
            res = max(res,sum);
            
            for(auto it:ump){
                pq.push({it.first,it.second});
            }
            int last1 = pq.top().second; pq.pop();
            int last2 = pq.top().second;
            sum = last2 - last1;
            
            ump.erase(s[last1]);
            ump[s[i]]=i;
            sum++;
        
            
        }else{
            ump[s[i]]=i;
            sum++;
        }
    }
    return res;
}

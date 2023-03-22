//===類似題===
1402. Reducing Dishes
2456. Most Popular Video Creator
1100. Find K-Length Substrings With No Repeated Characters
1024. Video Stitching

//===思路===
(*)Greedy, 有多少,用多少
(*)出現次數為奇數的字母, 個數一定不能超過K個  
- odd<=k
    |   \-> 題意,最多k個
    |     
     \-出現奇數個的字母,有odd個
    
(*)所有偶數可以拆分, 也可以合為一個
aa,bb,cc,dd 
- aa,bb,cc,dd 有四個  
- dcbaabcd 有一個 => "有多少,用多少"
//========
bool canConstruct(string s, int k) {
    unordered_map<int,int> mp;
    int odd = 0;
    for(char a:s) mp[a]++;
    for(auto a:mp){
        if(a.second%2) odd++;
    }
    return k<=s.size() && odd<=k;
}

bool canConstruct(string s, int k){
  vector<int> cnt(26,0);
  int odd = 0;
  for(char x:s) ++cnt[x-'a'];
  for(int i=0; i<cnt.size(); i++)
    if(cnt[i]%2) odd++;
  
  return odd<=k && k<=s.size();
                  //s.size() 大於k的部分可以是出現"偶數個數的字母"
}

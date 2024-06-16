//=== more challenge ===
1768. Merge Strings Alternately
2402. Meeting Rooms III
1267. Count Servers that Communicate
//=== 思路 ===
(*)dp運算, 
(*)刪除法, 當下依序刪除字串的其中一個字元, 查看是否在之前的字串中出現過

1. 將vector<sring> 做長度排列, 由短到長
2. 建立unordered_map<sring,int>, 紀錄出現的string和對應的index
3. 建立dp; vector<int> 紀錄每一個index產生的longest string chain
4.每次新的string, 皆依序刪除字串的其中一個字元, 查看是否在之前的字串中出現過
- 若出現過, 則找到對應的index, 此index對應的dp, 是longest string chain數目

5.dp update
- dp起始值為1, 每一個string自己形成一個chain, 所以值為1  
- string刪除的char出現在 map中則
dp[i] = max(dp[i], dp[ump[string]]+1);
res = max(res,dp[i]);//紀錄最長的longest string chain

- 如果沒有出現, 不做處理
  
int longestStrChain(vector<string>& words) {
    int n = words.size();
    unordered_map<string,int> ump;//<sting in words, index>
    vector<int> dp(n,1);
    int res = 1;

    sort(words.begin(),words.end(),[](string& a,string& b){
        return a.size()<b.size();
    });        
    ump[words[0]] = 0;
    
    for(int i=1; i<n; ++i){
        string str = words[i];
        for(int j=0; j<str.size(); ++j){
            string tmp = str;
            tmp.erase(tmp.begin()+j);
            
            if(ump.count(tmp)){
                dp[i]=max(dp[i],dp[ump[tmp]]+1);
                res = max(res,dp[i]);
            }
        }
        ump[words[i]]=i;
    }
    return res;        
}

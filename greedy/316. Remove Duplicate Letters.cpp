//===類似題===
317. Shortest Distance from All Buildings
2030. Smallest K-Length Subsequence With Occurrences of a Letter
//==思路===
(*)只做刪除,不重新排列

1.紀錄每一個出現letter的次數
2.定義一新的 string, 此string作為解; 定義一陣列exist, 表示在string中出現的letter
2.2 不對原字串做變動, 只對原字串做判斷
    解為新字串, 從對原字串做判斷而來
    
    
//===
string helper0(string s){
    int mp[256]={0};
    int exist[256]={0};
    string res="0";
    for(int i=0;i<s.size();i++) mp[s[i]]++;

    for(int i=0;i<s.size(); i++){
        mp[s[i]]--;
        if(exist[s[i]]) continue;//不把重複在res的letter加入res中,所以直接pass

//letter沒有出現在res中, 所以要加入res.
//如果新增的letter, 小於所有res的letter; 且原本在res中的letter有1個以上(mp中記錄),則將res中的letter移除
        while(s[i]<res.back() && mp[res.back()]){//從res的back判斷
            exist[res.back()]=0;//要先記錄, 在pop, 不然會出錯
            res.pop_back();
//                visited[res.back()]=0;//record first
        }
        res+=s[i];//letter沒有出現在res中, 所以要加入res.
        exist[s[i]]=1;
    }
    return res.substr(1);
}
string removeDuplicateLetters(string s) {
        return helper0(s);
}

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

//===寫法2===
string removeDuplicateLetters(string s) {
    unordered_map<char,int> ump;//<character, count> 原本string的character個數
    unordered_map<char,int> res_ump;//<character, count> 新string的character個數
    string res;
    
    for(char c:s) ump[c]++;
    for(int i=0; i<s.size(); ++i){
        ump[s[i]]--;    
        if(res.size()==0){
            res = res + s[i];
            res_ump[s[i]]++;
        } else {
            /*1.如果新string的最後一個char大於當下的char
              2.如果新string的最後一個char, 存在於之後遍歷的元素中
              3.如果新string中, 沒有存在當下的char
              - 直接將新的string.back()移除
            */
            while(res.size() && res.back()>=s[i] && ump[res.back()] && !res_ump.count(s[i])){
                res_ump[res.back()]--;
                if(res_ump[res.back()]==0) res_ump.erase(res.back());
                res.pop_back();
            }
            /*  1.移除完之後, 再判斷一次,是否有跟新string的元素重複
                2.因為上面不成立有可能是, 1,2不成立
            */
            if(!res_ump.count(s[i])){
                res.push_back(s[i]);
                res_ump[s[i]]++;
            }
        }
    }
    return res;
}



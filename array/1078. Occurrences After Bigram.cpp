//===類似題===
1080. Insufficient Nodes in Root to Leaf Paths
1960. Maximum Product of the Length of Two Palindromic Substrings
1087. Brace Expansion
2135. Count Words Obtained After Adding a Letter
//===思路===
1.記錄每一個字串出現的(起點,終點); 形成一串列
2.遍歷此串列, 如果first相等於(起點,終點)所形成的字串, 再比較下一個(起點,終點)是否等於second
3.如果都相等, 就可以將third紀錄於"解"中
//===
vector<string> helper0(string text, string first, string second){
    vector<pair<int,int>> r;
    vector<string> res;
    string t = text;
    
    t.push_back(' ');//多加一個space, 避免搜尋到的條件沒有記錄到
    for(int i=0,start=0;i<t.size();i++){
        if(t[i]==' '){
            pair<int,int> p={start,i};
            r.push_back(p);
            start=i+1;
        }
    }
    for(int i=0; i<r.size(); i++){
        if(first==t.substr(r[i].first, r[i].second-r[i].first) && (i+2)<r.size()){//(1)比較字串 (2)判斷是否存在third
            if(second==t.substr(r[i+1].first, r[i+1].second-r[i+1].first)){//比較second 
                res.push_back(t.substr(r[i+2].first, r[i+2].second-r[i+2].first));//紀錄third
            }   
        }
    }
    return res;
}
vector<string> findOcurrences(string text, string first, string second){
    return helper0(text,first,second);
}

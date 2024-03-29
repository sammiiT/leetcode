//====類似題===
764. Largest Plus Sign
2405. Optimal Partition of String
//===思路====
1.紀錄每一個相同的字元出現的起始位置,末位置 => unordered_map<char,pair<int,int>>
2.(起始位置,末位置)可以重新排列, 以起始位置做比較, 遞增 => priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>
3.若區間有重疊,則合併, 讓每一個字元僅出現在單一的區間
4.得到的每一個區間, 就是每個一partition的範圍; 即可得到範圍的長度
//====
struct cmp{
  bool operator()(pair<int,int>& a, pair<int,int>& b){
      return a.first>b.first;
  }  
};

vector<int> helper0(string s) {
    unordered_map<char,pair<int,int>> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;    
    vector<pair<int,int>> res;
    vector<int> ret;
    
    for(int i=0;i<s.size();i++){//紀錄每一個相同的字元出現的起始位置,末位置 
        pair<int,int> p;
        if(mp.count(s[i])){
            mp[s[i]].second = max(mp[s[i]].second,i);
        }else{
            p.first = p.second = i;//(*)第一次出現, 把first和,second都記錄為同一位址..之後重複出現再修改second
            mp[s[i]]=p;            //如果只出現一次,second -first +1 = 1;
        }
    }
    for(auto a:mp) pq.push(a.second);//(起始位置,末位置)可以重新排列, 以起始位置做比較, 遞增
  
    res.push_back(pq.top());
    pq.pop();
    while(!pq.empty()){//若區間有重疊,則合併, 讓每一個字元僅出現在單一的區間
        pair<int,int> p = pq.top();
        if(res[res.size()-1].second>=p.first){
            res[res.size()-1].first = min(res[res.size()-1].first, p.first);
            res[res.size()-1].second = max(res[res.size()-1].second, p.second);
        }else{
            res.push_back(p);
        }
        pq.pop();
    }
    for(int i=0;i<res.size();i++){//得到的每一個區間, 就是每個一partition的範圍; 即可得到範圍的長度
        ret.push_back(res[i].second-res[i].first+1);
    }
    return ret;
}

vector<int> partitionLabels(string s) {
        return helper0(s);
}

//=====思路=====
1.
2.  a...e...a...e...
        ^   ^
        |   第一個last
        |--找到第二個last, 位置會大於第一個last; 所以 last = max(last,m[s[i]]);    
            
//===========
vector<int> helper1(string s){
    unordered_map<char,int> mp;
    int start=0,last=0;
    vector<int> res;
    for(int i=0; i<s.size(); i++) mp[s[i]]=i;//紀錄最後一個位置
    
    for(int i=0; i<s.size(); i++){
        last = max(last,mp[s[i]]);//找到對應字元的最後一個位址, 並記錄在last
        if(last == i){//如果遍歷到第一個last
            res.push_back(i-start+1);//長度
            start = i+1;//下一個partition的start
        }
    }
    return res;
}

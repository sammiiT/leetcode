//===類似題====
693. Binary Number with Alternating Bits
1772. Sort Features by Popularity
2284. Sender With Largest Word Count
2341. Maximum Number of Pairs in Array

//===思路=====
1.一個unordered_map紀錄string出現的次數
2.一個priority_queue排列string出現的最多次數
3.priority_queue的比較方式
-出現最多次數的
-如果出現次數一樣,比較lexicographical order;比較小的lexicographical order排前面


//===
struct cmp{
    bool operator()(pair<string,int> a, pair<string,int> b){
        return a.second < b.second || (a.second == b.second && a.first > b.first);
                //比較多的排前面        //若兩sting出現次數相等, 則比較小的lexicographical order排前面
    }
};
vector<string> helper0(vector<string>& words, int k){
    unordered_map<string,int> m;//string ,count
    priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;

    vector<string> res; 

    for(string s:words){ m[s]++; }//找到每一個string出現的次數
    for(auto a:m){//作排列
        pq.push(make_pair(a.first,a.second));
    }
    while(!pq.empty()&&k){//找出出現最多的前k個
        pair<string,int> t = pq.top();
        res.push_back(t.first);
        pq.pop();
        k--;
    }
    return res;
}

//===寫法2===
(*) 前一個概念是由大排到小
(*) 這一個寫法是 由小排到大, 取priority_queue中的k個
    lexicalgraphic order 是由大排到小
=> 最後 priority_queue的排序還要再做一次reverse
        
struct cmp{
    bool operator()(pair<string,int>& a, pair<string,int>& b){
        if(a.second > b.second) return true;
        if(a.second==b.second){
            return a.first < b.first;
        }
        return false;
    }
};
vector<string> topKFrequent(vector<string>& words, int k) {
    priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq; 
    unordered_map<string,int> ump;
    vector<string> res;
    for(string str:words){
        ump[str]++;
    }
    for(auto it:ump){
        pq.push({it.first,it.second});
        if(pq.size()>k) pq.pop();
    }
    while(!pq.empty()){
        res.insert(res.begin(), pq.top().first);
        pq.pop();
    }
    return res;
}


vector<string> topKFrequent(vector<string>& words, int k) {
    return helper0(words,k);
}

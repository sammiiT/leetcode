//===類似題===
768. Max Chunks To Make Sorted II
358. Rearrange String k Distance Apart
621. Task Scheduler
1405. Longest Happy String

//===思路===
(*)unordered_map紀錄字元出現的次數
(*)priority_queue排列出現字元出現最多的順序
1.如果個別字元出現的次數多餘陣列總數的一半(s.size()+1)/2; 則代表沒有辦法滿足adjencent分開的條件, 一定會並排
2.重新作排列時,一次從priority_queue取兩個不同的字元, 個取出一個放入陣列, 剩下的再push回priority_queue
3.重複2步驟, 直到priority_queue的個數小於2個
4.剩一個, 將其再放入陣列中, 即解

//======
struct cmp{
    bool operator()(pair<char,int> a, pair<char,int> b){
        return a.second < b.second;
    };
};
string helper0(string s){
    unordered_map<char,int> m;
    priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
    string res;

    for(char c:s) m[c]++;
    for(auto a:m) {
        if(a.second>(s.size()+1)/2) return "";
        pq.push(make_pair(a.first,a.second));
    }

    while(pq.size()>=2){
        pair<char,int> x = pq.top();pq.pop(); 
        pair<char,int> y = pq.top();pq.pop();
        res.push_back(x.first);
        res.push_back(y.first);
        if(--x.second>0) pq.push(x);
        if(--y.second>0) pq.push(y);
    }
    if(pq.size()) res.push_back(pq.top().first);
    return res;
}

    string reorganizeString(string s) {
        return helper0(s);
    }

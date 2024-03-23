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

//===寫法2(思路2)===
(*)用priority_queue來解
1.將所有char依據多寡存到priority_queue中
2.從priority_queue中一次取兩個元素出來, 做為新的string的元素
-一次取兩個是為了避免"依次取再push到priority_queue",下依次會取到相同的char
如: vvvlo在priority_queue中是
vvv 和 l,o
取一個v,  剩下的vv再push到prioirity_queue,會變成 vv,l,o
再次取,還是會取到v , 結果會重複(如:vv)  

-一次取兩個
vvv,l 和o
取一個v, 取一個l ,剩下的vv再push到prioirity_queue,會變成 vv,o
res = vl , pq中是 vv,o; 所以不會重複 (如: vlv)    


string reorganizeString(string s) {
        string res;
        unordered_map<char,int> ump;
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
        for(char& c:s) ump[c]++;
        for(auto it:ump) pq.push({it.first,it.second});

        do{
            vector<pair<char,int>> vp;
            for(int i=0;!pq.empty() && i<2; ++i){//一次取兩個
                pair<char,int> p = pq.top();pq.pop();
                vp.push_back(p);
            }

            for(int i=0; i<vp.size(); ++i){//取出的兩個做為結果string的排列元素
                res.push_back(vp[i].first);
                if(vp[i].second-1) pq.push({vp[i].first,vp[i].second-1});
            }
        }while(!pq.empty() && res.back()!=pq.top().first);

        return res.size()==s.size()?res:"";//如果有重複, 最後string的長度不會與原長度相等, 會比較短
}

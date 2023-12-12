//===類似題===
1579. Remove Max Number of Edges to Keep Graph Fully Traversable
2562. Find the Array Concatenation Value
161. One Edit Distance
2370. Longest Ideal Subsequence

//===思路1====
(*)用priority_queue
1.連續出現的字元,用priority_queue來記錄, 紀錄pair<char,int> (字元,時間)
- priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>  是由小排到大

2.每次都將colors[i]push至priority_queue中:
-如果下一個字元等於q.top().first, 則neededTime[i] 推入priority_queue中
-如果下一個字元不等於q.top().first 且q.size()>=2, 則將q的元素pop出來;(q.size()-1)個;並累加其最小的元素值
--q.size()-1是前面的time都是最小(依照題意)
-最後要把q的最後一個pop出來, 再將當下的 (colors[i],neededTime[i])推入, 以進行下一輪的判斷計算


3.數列有邊界問題,所以loop執行完之後還要再判斷一次q.size()
-如果q.size()>=2 代表有連續兩個重複的字元, 所以要在累加一次
//=======
bool operator()(pair<char,int> a, pair<char,int> b){
    return a.second>b.second;
}
};
int helper0(string colors, vector<int>& neededTime) {
    priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
    int res = 0;
    for(int i=0; i<colors.size(); ++i){
        if(pq.size()==0 || colors[i]==pq.top().first) pq.push(make_pair(colors[i],neededTime[i]));
        else {//pq.top()!=colors[i]
            while(pq.size()>=2){
                res+=pq.top().second;
                pq.pop();
            }
            pq.pop();//把最後一個相同color的balloon移除
            pq.push(make_pair(colors[i],neededTime[i]));//更換成最新的balloon
        }
    }
    while(pq.size()>=2){
        res+=pq.top().second;
        pq.pop();
    }
    return res;
}

//===思路2==
(*)當遇到重複的字元,就累加,並記錄此重複字元的字串的最大neededTime
- 依據題意,花的時間最少,所以累加的(全部時間-最大時間=所有花最少時間的總和)

//======
int helper1(string colors, vector<int>& neededTime){
    int i,j;
    int res = 0;
    int tmp = 0;
    int mx = neededTime[0];

    for(j=0, i=0;i<colors.size();++i){
       if(colors[j]==colors[i]){
           mx = max(mx,neededTime[i]);
           tmp+=neededTime[i];
       } else {//colors[i]!=colors[j]
            if(i-j>=2){ 
               tmp-=mx;
               res+=tmp; 
            }
            mx = neededTime[i];
            tmp = neededTime[i];
            j=i;
       }             
    }
    if(i-j>=2) {
        tmp-=mx;
        res+=tmp;
    }
    return res;
}

//===思路3====
(*)出現連續相同的顏色,比較時間
(*)兩顏色不適連續, 則更換比較標的
(*) priority_queue
1.priority_queue<pair<char,int>>
- char = color[i]
- int = neededTime[i]
2.遍歷colors陣列, 
- 如果當下color等於前一個color, 則比較neededTime大小, pop出較小的time並累加
- 如果當下color不等於前一個color, 則pop元素, 再重新push新的color



static struct cmp{
    bool operator()(pair<char,int> a, pair<char,int> b){
        return a.second>b.second;
    }
};
int minCost(string colors, vector<int>& neededTime){
    priority_queue<pair<char,int>,vector<pair<char,int>>, cmp> pq;
    int res = 0;
    
    pq.push({colors[0],neededTime[0]});
    
    for(int i=1; i<colors.size(); ++i){
        if(colors[i]==pq.top().first){
            pq.push({colors[i],neededTime[i]});
            res += pq.top().second;
            pq.pop();
        }else{//colors[i]!=pq.top().first;
            pq.pop();
            pq.push({colors[i],neededTime[i]});
        }
    }
    return res;
}
//===思路4===
(*)用unordered_map做題

int helper2(string colors, vector<int>& neededTime){
    unordered_map<char,pair<int,int>> map;//color, index, maximum_timecout
    int res = 0;
    
    for(int i=0; i<colors.size(); ++i){
        char c = colors[i];
        
        if(map.count(c)){
            if(map[c].first+1 == i){
                if(neededTime[i]>=map[c].second) {
                    res += map[c].second;
                    map[c].second = neededTime[i] ;       
                }else{
                    res+=neededTime[i];          
                }
                map[c].first=i;
            } else {
                map[c].first = i;
                map[c].second = neededTime[i];
            }
        }else{
            map[c] = {i,neededTime[i]};
        }
    }
    return res;
}

//===寫法5====
(*)只需遍歷一次陣列
1.建立兩個index, i=遍歷索引, j=顏色比較索引
- j更新: 當顏色不相同時 colors[i]!=colors[j]
- j更新: 當顏色相同且[j]時間小於[i]時間 

2.每次遇到相同的顏色,就比較花費時間, 取較小的那一個

int minCost(string colors, vector<int>& neededTime) {
    int res = 0;
    int total = neededTime.size();
    
    for(int j=0,i=1; i<total; ++i){
        int t = 0;
        if(colors[j]==colors[i]){//顏色相同
            if(neededTime[j]<neededTime[i]){//時間[j]小於時間[i]
                t = neededTime[j];//記錄較小的時間
                j = i;//更新j索引
            }else{//neededTime[j]>=neededTime[i]
                t = neededTime[i];//記錄較小的時間, 但不更新j索引
            }
            res += t;
        } else {//colors[j]!=colors[i]
            j = i;//更新j索引
        }
    }
    return res;        
}








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
            pq.pop();
            pq.push(make_pair(colors[i],neededTime[i]));
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



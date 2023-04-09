//===類似題====
1963. Minimum Number of Swaps to Make the String Balanced
2208. Minimum Operations to Halve Array Sum
2530. Maximal Score After Applying K Operations
2558. Take Gifts From the Richest Pile

//===思路===
(*)greedy概念
(*)用priority_queue<int>
-將每一個元素push到priority_queue中, pq中的top是數列中的最大值

(*)每次取出pq中的top(), 執行題意 piles[i]-floor(piles[i]/2);
-執行運算後, 再將此值push回pq中

(*)上述動作執行k次, 最後pq中的值累加即為解

//====
int helper0(vector<int>& piles, int k){
    int sum=0;
    priority_queue<int> pq;
    for(int a:piles) pq.push(a);
    while(k--){
        int t = pq.top();
        pq.pop();
        t = t-t/2;//piles[i]-floor(piles[i]/2);
        pq.push(t);//再將此值push回pq中
    }
    while(!pq.empty()) {//pq中的值累加即為解
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}

int helper1(vector<int>& piles, int k){
    int sum=0;
    priority_queue<int> pq;
    for(int a:piles) {
        sum+=a;
        pq.push(a);
    }    
    while(k--){
        int t = pq.top();
        pq.pop();
        sum-=t/2;//每次運算,順便減去floor(piles[i]/2)
        t-=t/2;
        pq.push(t);
    }
    return sum;    
}

    int minStoneSum(vector<int>& piles, int k) {
        return helper1(piles,k);
//        return helper0(piles,k);
    }
};

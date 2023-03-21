//===類似題===
1339. Maximum Product of Splitted Binary Tree
1893. Check if All the Integers in a Range Are Covered
1743. Restore the Array From Adjacent Pairs
2275. Largest Combination With Bitwise AND Greater Than Zero

//===思路===
(*) greedy概念
1.unordered_map<int,int>紀錄每一個數值出現的次數
2.將map中的每一個元素, 依照出現次數的多寡作排列; 此排列可以由priority_queue完成或用sort完成
3.依次pop出queue中出現次數的最大數值,並累加, 當累加>=size/2 即為解.
//====
static struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;//val, counts
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        for(int a:arr){ mp[a]++;}
        for(auto b:mp) { pq.push(make_pair(b.first,b.second)); }

        int cnt=0;
        int res = 0;
        int n = arr.size();
        while(!pq.empty()){
            cnt+=pq.top().second;
            pq.pop();
            res+=1;
            if(cnt>=n/2) break;        
        }
        return res;
    }
//====思路2====
(*)用vector依照出現各數多寡做排列

int helper1(vector<int>& arr){
    unordered_map<int,int> mp;//val,count
    vector<pair<int,int>> nums;
    int res = 0,cnt = 0,n = arr.size();

    for(int a:arr) mp[a]++;
    for(auto a:mp){ nums.push_back(make_pair(a.first,a.second));
    }
    sort(nums.begin(),nums.end(),
        [](pair<int,int> a,pair<int,int> b){return a.second > b.second;});

    for(auto a:nums){
        cnt+=a.second;
        res+=1;
        if(cnt>=n/2) {
            break;
        }
    }
    return res;
}


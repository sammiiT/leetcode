//===類似題===
2206. Divide Array Into Equal Pairs
2190. Most Frequent Number Following Key In an Array
2341. Maximum Number of Pairs in Array

//===思路===
struct  cmp{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        if(a.second > b.second) return true;
        if(a.second==b.second){
            if(a.first < b.first) return true;
            else return false;
        }
        return false;
    }
};

vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;//value, count
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        vector<int> res;

        for(int i:nums) ump[i]++;
        for(auto it:ump){ pq.push({it.first,it.second}); }
        
        while(!pq.empty()){
            pair<int,int> p = pq.top(); pq.pop();
            for(int i=0;i<p.second;++i){
                res.push_back(p.first);
            }
        }
        return res;
}

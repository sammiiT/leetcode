//===類似題===
348. Design Tic-Tac-Toe
192. Word Frequency
659. Split Array into Consecutive Subsequences
692. Top K Frequent Words
//===思路===

//======
struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second< b.second;
    }
};
vector<int> helper1(vector<int>& nums, int k){
    unordered_map<int, int> m;//val,count
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;//val,count
    vector<int> res;
    for(int a:nums) m[a]++;
    for(auto a: m) pq.push(make_pair(a.first,a.second));

    for(int i=0;i<k;i++){
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;

}
vector<int> topKFrequent(vector<int>& nums, int k) {
        return helper1(nums,k);
//        return helper0(nums,k);
}

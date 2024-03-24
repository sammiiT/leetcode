//===類似題===
76. Minimum Window Substring
159. Longest Substring with At Most Two Distinct Characters
265. Paint House II

//===思路1====
(*) sliding_window + monotonic_queue

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> maxq;
    int f=0,r=0;

    for(r=0; r<k; ++r){
        while(!maxq.empty() && nums[r]>maxq.back()) maxq.pop_back();
        maxq.push_back(nums[r]);
    }
    res.push_back(maxq.front());

    while(r<nums.size()){
        while(!maxq.empty() && nums[r]>maxq.back()) maxq.pop_back();
        maxq.push_back(nums[r]);
        
        if(maxq.front()==nums[f]) maxq.pop_front();  
        
        res.push_back(maxq.front());
        ++r;
        ++f;//keep window size in "k" units
    }  
    return res; 
}


//===思路2====
(*) sliding_window + multi-set

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int> mst;
    vector<int> res;
    int f=0,r=0;

    for(r=0; r<k; ++r) mst.insert(nums[r]);
    res.push_back(*rbegin(mst));

    while(r<nums.size()){
        mst.insert(nums[r]);
        mst.erase(mst.euqal_range(nums[f]).first);
        res.push_back(*rbegin(mst));
        ++r;
        ++f;
    }
    return res;
}

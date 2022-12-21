//====類似題====
374. Guess Number Higher or Lower
More challenges
719. Find K-th Smallest Pair Distance
2040. Kth Smallest Product of Two Sorted Arrays

//====思路=
1.先找出base的配對, (nums1[0],nums2[0]);(nums1[0],nums2[1]);(nums1[0],nums2[2])...(nums1[0],nums2[i])
2.利用priority map 紀錄sum最小的兩個數列index.
3.每一次新增一個element到priority queue時, 先判斷nums1的index是否超過nums1.size()  
3.1 新增element到pq,依據前一個pq中的nums1 index值

        0    1    2    3 
nums1   o    o    o    o    
        |\______ 
        |\__    \  
        |   \    \
nums2   x    x    x

(*)一開始, nums1[0],全部配對nums2[i]
(*)第一次 pq.top()是, nums1[0],nums2[0]
(*)所以下一次推入pq的element是 nums1[0+1], nums2[0]; 依據前一個pq中的的index.

//=====
struct info{
        int x;
        int y;
        int sum;
};
struct cmp{
    bool operator()(struct info &p, struct info &q){ return p.sum > q.sum; } };

vector<vector<int>> helper1(vector<int>& nums1, vector<int>& nums2, int k){
        priority_queue<struct info, vector<struct info>, cmp> pq;
        vector<vector<int>> res;

        for(int i=0; i<nums2.size(); i++){
            pq.push({0,i,nums1[0]+nums2[i]});//nums1[0]配對所有的nums2元素
        }

        while(res.size()<k && !pq.empty()){
            struct info t = pq.top();//element推出pq
            pq.pop();
            res.push_back({nums1[t.x], nums2[t.y]});

            if(t.x+1<nums1.size()){//element 推入pq
//因為nums1[0]已經配對所有的nums2; 所以,下一個開始, index要+1, 依據當下的nums1 index  
                pq.push({t.x+1,t.y,nums1[t.x+1]+nums2[t.y]});
            }
        }
        return res;
}

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        return helper1(nums1,nums2, k);
//        return helper0(nums1, nums2, k);//Time Limit Exceeded
}

//====
//Time limit Exceeded
vector<vector<int>> helper0(vector<int>& nums1, vector<int>& nums2, int k){
        vector<vector<int>> res;    
        for(int i=0; i<nums1.size(); i++){
            for(int j=0;j<nums2.size();j++){
                res.push_back({nums1[i],nums2[j]});
            }
        }
        sort(res.begin(),res.end(),[](vector<int>& a, vector<int>& b){return a[0]+a[1]<b[0]+b[1];});
        if(res.size()>k) res.erase(res.begin()+k,res.end());
        return res;
}

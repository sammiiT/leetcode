//===類似題===

//===思路===
(*)用quque<pair<int,int>>
pair<int,int> = (index,value)

(*)遍歷數列
-當遇到negative value, 則push到queue
-當遇到positive value, 不push到queue

(*)考慮window size, 每次要push到queue之前, 先判斷
-window_head的index是不是等於 queue.front()的index ; 則先將queue做pop
-做完上述動作, 在判斷新的數值是否為negative; 是則push

(*)每次對window_head做update

(*)對res.push_back()

vector<int> printFirstNegativeInteger(vector<int>& nums, int k){
    queue<pair<int,int>> q;//index,  value
    vector<int> res;
    int i=0,j=0;
    
    for(i=0;i<k;++i){
        if(nums[i]<0){
            q.push({i,nums[i]});
        }
    }
    if(q.size()){ res.push_back(q.front().second);
    }else { res.push_back(0); }
    
    j=0;
    for(;i<nums.size();++i){
        if(q.size() && j==q.front().first) q.pop();
        if(nums[i]<0) q.push({i,nums[i]});
        ++j;
        
        if(q.size()) res.push_back(q.front().second);
        else res.push_back(0);
    }
    
    return res;
    
}

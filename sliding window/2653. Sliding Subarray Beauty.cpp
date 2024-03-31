//===more challange===
2664. The Knight’s Tour
2418. Sort the People
1626. Best Team With No Conflicts

//===思路====
(*) sliding_window + counter

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    int n = nums.size();
    int cnt[101] = {0};
    int sum=0,i=0,f=0;
    vector<int> ans;
    
//first beauty "0~49" are negative    
    for(;i<k; ++i) {
        ++cnt[nums[i]+50];
    }
    for(int j=0; j<101; ++j){
        sum+=cnt[j];
        if(sum<x) continue;
        if(j-50<0) ans.push_back(j-50);
        else ans.push_back(0);
        break;
    }
    
//each beauty after first one    
    for(;i<nums.size(); ++i){
        sum=0;
        --cnt[nums[f]+50];
        ++cnt[nums[i]+50];
        
        for(int j=0; j<101; ++j){
            sum+=cnt[j];
            if(sum<x) continue;
            if(j-50<0) ans.push_back(j-50);
            else ans.push_back(0);
            break;
        }
        ++f;
    }
    return ans;
}

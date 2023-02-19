//===類似題===
698. Partition to K Equal Sum Subsets
857. Minimum Cost to Hire K Workers
2554. Maximum Number of Integers to Choose From a Range I
2305. Fair Distribution of Cookies
//===思路===
1. unordered_map<int, vector<int>> 紀錄出現的數值, 數值起始index,結束index, 總個數
int => 紀錄出現的數值
vector<int> => [0]=起始index;[1]=結束index;[2]=總個數

2.第一次遍歷陣列
紀錄map

3.第二次遍歷map
- 找出對應的max個數,並利用start和end索引,求出 length
- 找出最短的length並回傳

//====
int helper0(vector<int>& nums){
    unordered_map<int,vector<int>> m;//val, (start,end,count)
    int mx = 0;
    int ret = INT_MAX;
    for(int i=0; i<nums.size(); i++){//for(int a:nums){
        if(m.count(nums[i])){
            m[nums[i]].at(1) = i;    
        }
        else{
            m[nums[i]].push_back(i);
            m[nums[i]].push_back(i);
            m[nums[i]].push_back(0);
        }
        mx = max(mx,++m[nums[i]][2]);
    }

    for(auto a:m){
        if(mx==(a.second.at(2))){
            ret = min(ret,a.second.at(1)-a.second.at(0)+1);
        }
    }
    return ret;
}
//====
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> m;//key = val v=count
        unordered_map<int,pair<int,int>> pos;//key = val, v= start:end
        int degree = INT_MIN;
        int res = INT_MAX;
        
        for(int i=0;i<n;++i){
            if(++m[nums[i]]==1){
                pos[nums[i]]={i,i};
            }else{
                pos[nums[i]].second = i;
            }
            degree = max(degree,m[nums[i]]);
        }
        
        for(auto a:m){
            if(a.second == degree){
                res = min(res,pos[a.first].second-pos[a.first].first+1);             }
        }
        return res;    

        
    }
};

//===類似題===
399. Evaluate Division
382. Linked List Random Node
710. Random Pick with Blacklist
//===思路==
(*) 用unordered_ma<int,vector<int>>紀錄每一個數字的出現的位址
- int = 出現的數字
- vector<int> 識字出現的位置

(*)挑選的target必須出現的機率相同
- 用rand()函數
- 數字出現的次數 ,可以用vector.size();
- rand()%vector.size();出現的index


//=====
class Solution {
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size(); ++i) 
            mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return mp[target][rand()%mp[target].size()];
    }

private:
unordered_map<int,vector<int>> mp;

};

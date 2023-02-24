//===類似題===
79. Word Search
320. Generalized Abbreviation
784. Letter Case Permutation
1982. Find Array Given Subset Sums
//===思路===
(*)DFS 算法
1.每一個節點都可以當作root節點
-root節點就是,除了此節點外,其他的節點都會進到下一個遞迴level 
Ex:



//====

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        
        helper(nums,0,out,res);
        return res;
        
    }
    void helper(vector<int> &nums,
               int start,
               vector<int>& out,
               vector<vector<int>>& res){
        res.push_back(out);
        for(int i=start; i<nums.size(); ++i){
            out.push_back(nums[i]);
            helper(nums,i+1,out,res);
            out.pop_back();
        }
    }
};

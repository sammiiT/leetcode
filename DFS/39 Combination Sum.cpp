//===類似題===
40. Combination Sum II
More challenges
17. Letter Combinations of a Phone Number
254. Factor Combinations
//===思路===
(*)DFS算法
1.每一個節點都可以當作root, 往下一層運算的節點,都市是此root的child
2.每一個child都可當作一個"新的路徑"; DFS就是羅列所有路徑的可能性

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

可以(2,2,3),但從3開始時,不能往回計算, 所以for迴圈必須
for(int i=start; i<candidates.size();i++)
當i=0時, 跳到下一個level, i還是可以等於0開始      
當i=1時, 跳到下一個level, i還是從1開始, 不會回到0  
//=====
void helper(vector<int>& candidates, int target, int start,vector<int>& out, vector<vector<int>>& res){
    if(target<0) return;
    if(target==0) {
        res.push_back(out);
        return;            
    }
    for(int i=start; i<candidates.size();i++){
        out.push_back(candidates[i]);
        helper(candidates,target-candidates[i],i,out,res);
        out.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> out;
    vector<vector<int>> res;
    helper(candidates,target,0,out,res);
    return res;
}

//=========
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        
        helper(candidates,target,0,out,res);
        
        return res;
    }
    
    void helper(vector<int>& candidates,
                int target,
                int start,
                vector<int>& out,
                vector<vector<int>>& res)
    {
        if(target<0) return;
        if(target==0){
            res.push_back(out);
            return;
        }
        
        for(int i=start;i<candidates.size();++i){
            out.push_back(candidates[i]);
            helper(candidates,target-candidates[i],i,out,res);
            out.pop_back();
        }
    }
};

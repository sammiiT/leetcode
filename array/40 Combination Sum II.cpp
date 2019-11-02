class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        if(candidates.size()<=0) return res;
        
        sort(candidates.begin(),candidates.end());
        
        helper(candidates,target, 0,out,res);
        return res;
    }
//1,1,2,5,6,7,10
    
    void helper(vector<int>& candidates, 
                int target,
                int start,
               vector<int> out,
               vector<vector<int>>& res){
        
        if(target<0) return;
        if(target==0){
            res.push_back(out);
            return;
        }
        
        for(int i=start; i<candidates.size(); ++i){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            out.push_back(candidates[i]);
            helper(candidates,target-candidates[i],i+1,out,res);
            out.pop_back();
        }
        
    }
};


/*

if(target<0) return;
        if(target==0){res.push_back(out);}
        
        for(int i=start;i<nums.size();++i){
//?????????? or ???????? ===> ???????            
            // if(i>start && (nums[i]==nums[i-1])) return;//??
            if(i>start && (candidates[i]==candidates[i-1])) continue;
                
            out.push_back(candidates[i]);
            helper(candidates,
                              target-candidates[i],
                              i+1,//(i+1)????????????????current??,?????(nums[i]==nums[i-1])???
                              out,
                              res);
            out.pop_back();

*/


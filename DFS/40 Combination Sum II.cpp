//===類似題===
41. First Missing Positive
2556. Disconnect Path in a Binary Matrix by at Most One Flip
1807. Evaluate the Bracket Pairs of a String
1550. Three Consecutive Odds
//===思路===
(*)DFS算法,跟Combination Sum的觀念一樣
(*)但不能出現重複解,所以必須先sort

(*)必須先sort,才能用判斷避免重複的解出現
[10,1,2,7,6,1,5] =>[1,1,2,5,6,7,10]
                    \ \--以此為root,會有解[1,2,5] 
                     \---以此為root,會有解 [1,2,5]  
兩個1會有重複解[1,2,5]               
//======
void helper1(vector<int>& candidates, 
            int target,
            int start,
            vector<int>& out,
            vector<vector<int>>& res) {
    if(target<0) return;
    if(target==0){
        res.push_back(out);
        return;
    }
    for(int i=start;i<candidates.size();i++){
        if(i>0 && candidates[i]==candidates[i-1]) continue;
        out.push_back(candidates[i]);
        helper1(candidates,target-candidates[i],i+1,out,res);
        out.pop_back();
    }
}

//===================================
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
            if(i>start && candidates[i]==candidates[i-1]) continue;//連續三個一樣的數值, 要避開重複解
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

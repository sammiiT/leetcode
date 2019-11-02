class Solution {
public:
//找出所有的可能性: DFS搜尋法    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9}; 
        vector<vector<int>> res;
        combinationSumDFS(nums,n,0,k,{},res);
        // combinationSumDFS3(k,n,1,{},res);
        return res;
    }
    
    
    void combinationSumDFS(vector<int>& nums,
                           int target,
                           int start,
                           int k,
                           vector<int> out,
                           vector<vector<int>> &res)
    {
        if(target<0) return;
        // if(k==0) return;
        // if(target==0) {res.push_back(out);}
        if((target==0) && (k==0)) {
            res.push_back(out);
            return;
        }//至少要有k個數字
        
        for(int i = start; i<nums.size(); ++i){
            out.push_back(nums[i]);
            combinationSumDFS(nums,target-nums[i],i+1,k-1,out,res);
            out.pop_back();
        }
    }

    
    void combinationSumDFS3(int k,//number of element.
                            int n,//target
                            int level,
                            vector<int> out,
                            vector<vector<int>> &res)
    {
        if(n<0){return;}
        if(n==0 && out.size()==k) res.push_back(out);
    
        for(int i = level; i<=9; ++i){
            out.push_back(i);
            combinationSumDFS3(k,n-i,i+1,out,res);
            out.pop_back();
        }
    
    }
    
    
    
    
    
    
    
};
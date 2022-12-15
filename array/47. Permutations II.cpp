//===類似題===
48. Rotate Image
267. Palindrome Permutation II
996. Number of Squareful Arrays

//====思路====

//====
void helper(vector<int>& nums, 
                int level, 
                vector<int>& chkFlag,
                vector<int>& out, 
                vector<vector<int>>& res){
        
        if(level>=nums.size()){
            res.push_back(out);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(chkFlag[i]) continue;//upper layer information
//            if(nums[i]==nums[i-1] && chkFlag[i-1]==0) break;
            if(i >0 && nums[i]==nums[i-1]&& chkFlag[i-1]==0) continue;

            chkFlag[i]=1;
            out.push_back(nums[i]);
            helper(nums, level+1, chkFlag, out, res);
            out.pop_back();
            chkFlag[i]=0;
        }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> chkFlag(nums.size(),0);
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(),nums.end());
        helper(nums, 0, chkFlag, out, res);
        return res;
}

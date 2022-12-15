//====類似題======
47. Permutations II
77. Combinations
60. Permutation Sequence
//====思路====
1.DFS解法
2.進入下一層的element =被push_back的element = 被挑選中的element
3.因為要往前挑選, 所以在同一階層中的每一個element, 在選新的element時, 都從頭開始選for(int i=0;i<nums.size();i++)
4.由3, 因為每次從0開始, 所以要有一個紀錄重複計次的vector

(*)回到上一層是因為 1.本層的for迴圈執行完畢 2.滿足條件,跳回上一層
//===
void helper0(vector<int>& nums, 
                 int level, 
                 vector<int>& chkFlag,
                 vector<int>& out, 
                 vector<vector<int>>& res){
        if(level>=nums.size()){
            res.push_back(out);
            return;
        }             

        for(int i=0;i<nums.size();i++){
            if(chkFlag[i]) continue;
            chkFlag[i]=1;
            out.push_back(nums[i]);
            helper0(nums, level+1, chkFlag, out, res);
            out.pop_back();
            chkFlag[i]=0;
        }
}

vector<vector<int>> permute(vector<int>& nums) {
        vector<int> out;
        vector<int> chkFlag(nums.size(),0);
        vector<vector<int>> res;

        helper0(nums, 0,chkFlag, out, res);
        return res;
}

//===類似題===
48. Rotate Image
267. Palindrome Permutation II
996. Number of Squareful Arrays
//====思路====
(*)DFS 算法
(*)數列要先經過sort, 排列成ascending 數列; [3,3,0,3]要排成 [0,3,3,3]運算才不會出錯
(*)因為有重複的數字,所以要多加上一個判斷式
- [1,1,2]
- 第二個1透過DFS算法,會出現1,1,2=>跟第一個1透過DFS算法出現的結果一樣
- if(i>0 && nums[i]==nums[i-1] && visited[i-1]==0)
                                     \--前一個沒有被訪問過,所以計算下去會重複

(*)"前一個沒有被訪問過,所以計算下去會重複" => 以[1,1,2]為例
當第一層從[1]開始, 因為前一個[0]沒有被訪問過; 所以產生的數列 [1,1,2]排列是[[1],[0],[2]] 會跟之前的排列[[0],[1],[2]]所得到的值重複

  
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

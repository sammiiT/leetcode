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


(*)permutation, subset題型差異
permutation:排列
-從array取出的element順序可以換
-因為順序可以對調, 所以loop中 (int i=0; i<num.size(); ++i)
--每一個root節點的下一個child節點, 都可以從"頭"開始選取
-每下一層level都會從位置"0"開始選起,要避免重複, 就要用visited[i]紀錄已經使用過的數值

subset:
-element從array取出不用連續
?????????????-element從array取出,"順序不能變" ?????????????????????
=>所以在loop中有 (int i=start;i<nums.size();++i)描述
=>每一層的開始,都從下一個節點開始

(*)數字不重複, 選取的位置不重複, 

//======
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
//===思路2====
(*)DFS算法,
(*)每一個節點都可以作為root節點,root下層節點都視為child
-每個root節點的child,必須再往下一層做DFS, 是因為同一階層都可以是"解"的其中一種;如
   o |  o |
 ----+----+----
   x |  o |  x  
 ----+----+----  
     |  x |
--在(1,1)位址上,可以走向(1,0),(1,2),(2,1)三個方向; 此三個方向都是(1,1)的child
--上述的三方向都是root(1,1)的child, 運算時都在同一階層; (1,0),(1,2),(2,1)在同一階層
  
  
(*)[1,2,3] 
        __1          ==> level 0          
       / /  \ 
      1 2     3      ==> level 1
       /|\   /| \ 
      1 2 3 1 2  3   ==>level 2
  
1->2->3 
1->1->x :不可以重複

1->2->1 :  因為不可以重複,所以1不行 
1->2->2 :  不可重複 

1->3->1 : 不可重複
1->3->2  
1->3->3 : 不可重複  
//====  
  
void helper1(vector<int>& nums, 
            vector<int>& visited ,
            vector<int>& out, 
            vector<vector<int>>& res){
    if(out.size()>=nums.size()){
        res.push_back(out);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i]) continue;
        visited[i]=1;
        out.push_back(nums[i]);
        helper1(nums,visited,out,res);
        out.pop_back();
        visited[i]=0;
    }
}
vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(),0);
        vector<int> out;
        vector<vector<int>> res;
        helper1(nums,visited,out,res);
        return res;
}

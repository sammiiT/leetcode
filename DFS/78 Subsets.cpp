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
 /--root點,之後每一個節點都是此節點的 child;
 | 
 a  b  c  d
  \
    b  <====以b為root,但為a的child
      \
       c <===以c為root,但為b的child
         \
          d <===以d為root,但為c的child

-以a為root節點,單一一個子節點,作為child節點 的配對有 (a,b); (a,c);(a,d)  
-以b為root節點,單一一個子節點,作為child節點 的配對有 (b,c);(b,d)  
-以c為root節點,單一一個子節點,作為child節點 的配對有 (c,d) 

=>(*)垂直level,沒有root節點跳出, 
  (*)平行(同一)level,沒有root節點跳出     
    
(a);(a,b);(a,b,c);(a,b,c,d);(a,c,d);(a,d)
(b);(b,c);(b,c,d);(b,d)
              \ \ --以d為root開始計算,(垂直level下一層沒有節點),跳出; 垂直層的下一層(平行層)沒有節點, 跳出 => 兩個條件都沒有, 再跳到上一層c層 
               \  
                \---以c來講, d之後沒有節點了, 平行level沒有root節點跳出(跳到上一level),跳回c層;與c相同的節點有d, 所以會再從d開始

//===思路===
[1,2,3] 用dfs的順序
1,
1,2,
1,2,3
1,3
2,
2,3
3

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
            helper(nums,i+1,out,res);//下一個節點可以當作root, 所以再往下一level做遞迴
            out.pop_back();//前一個root節點執行完之後, 必須移除(不然會重複), 再往下一節點做運算
        }
    }
};


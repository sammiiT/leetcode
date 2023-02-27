//===類似題====
78. Subsets
526. Beautiful Arrangement
282. Expression Add Operators
1079. Letter Tile Possibilities
//===思路====
(*)DFS算法
(*)每一個點都可以當作root節點, 
(*)root節點下的每一個level, 都可視為root的child
(*)每一個節點被選擇之後,下一個level都是其child

1. 依據題意, 是1-index, 所以在運算的時候, 要從1開始
2. 每次進入下一個level,都要判斷是否滿足條件; 最多k個

(*)DFS運算不會返回算到前一個數值, 按照順序,進入DFS之後,就不會再計算一次了
-- [1,2] 不會計算到 [2,1]; 除非原始題目是[2,1,...]排列

//====
void helper(int n,
            int k, 
            int start,
            vector<int>& out, 
            vector<vector<int>>& res){
    if(out.size()==k){ 
        res.push_back(out);
        return;
    }
    
    for(int i=start; i<=n; i++){
        out.push_back(i);
        helper(n, k, i+1, out, res);
        out.pop_back();    
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<int> out;
    vector<vector<int>> res;
    helper(n,k,1,out,res);  
    return res; 
}

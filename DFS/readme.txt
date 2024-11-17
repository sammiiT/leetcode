(*)DFS(Depth-First-Search)深度優先搜尋
-DFS是stack的概念
-DFS是從一個節點開始, 會一直深入到最後一層, 每一次進入新的一層時, 可做計算
-DFS可以在同一個level做判斷, 或在下一個level做節點判斷; 
--因為DFS每一次指判斷一個節點, 不像BFS,會將所有不滿足的節點都push致queue中,導致計算量過大

ex1: 棋盤                           ex2: 二元樹 
從A節點開始找起,                     從A節點開始找起,
DFS會算D->G->H->I;                  DFS會算B->D->H;
每一個節點都是下一層,                每一個節點都是下一層,
直到最後一層I節點                    直到最後一層H節點                    
    +---+---+---+                         *A
    | A | B | C |                        /  \
    +-|-+---+---+                      *B    C
    | D | E | F |                     /  \   / \
    +-|-+---+---+                   *D   E  F   G 
    | G ->H ->I |                   / \
    +---+---+---+                 *H   I

(*)有些DFS題目必須用一個buffer記憶訪問過的節點,目的是為了避免重複訪問;如
- 棋盤格類型的DFS; 會用一個二維陣列 vector<vector<int>> visited, 來紀錄是否訪問過
if(x<0||x>=m||y<0||y>=n||visited[x][y]) return;

- 一維陣列防止重複訪問, 如題目 valid palindrome III
-- memo就是紀錄已經訪問過的節點, 
if(memo[start][end]!=(-1)) return memo[start][end];

上層的   (start@,end@)
          |  \____  \_____________
          |        \               \
下層的 (start0,end0) (start1,end1)  (start#,end#)           
        |  \              |
        |    \_______     |
        |             \   | 
再下層 (start%,end%)  (start2,end2)


(*)
利用 DFS + memory 解法, 通常是在求單一路徑下的所有可能; 每一個走過的節點不可以重複, 已經走過的節點用memory紀錄; 如題目
- word break

但 DFS + memory解法, 不適用於 路徑節點重複的 題型; 如題目
- word break II 
- concatenated words


(*)dfs函式帶有回傳參數:
- 預先得知最底層的結果, 可用於 memory 題型; 將最底層的結果用memory紀錄, 防止重複運算
- 回傳值可用來決定, 1.下一個運算的方向, 2.記錄起來防止重複運算 
- 如 bool dfs(xxx,) ; 此回傳值(bool)可帶入memory buffer中 
- 有回傳參數的dfs算法, 通常是所有可能的路徑中,  單一路徑節不可重複計算
  窮盡所有可能,若找到一個解, 即回傳結果; 後面的解會被忽略

如: string = dogcatsand; wordDict={dog,cat,cats,and,sand}
組合路徑有 dog->cat->sand; dog->cats->and 
當其中一個路徑滿足(dog->cat->sand), 則回傳到最上層, 不會再往下考慮(dog->cats->and) 

如: string = catsanddogapple;  wordDict={cat,and,sand,dog,apple}
搜尋路徑一:
cat->sand->dog->apple 
dog對應的memo是true

搜尋路徑二:
cats->and->dog->apple
第二次又找到dog, memo已經有紀錄, 所以不用再繼續往apple找下去


(*)dfs函式不帶回傳值參數: 
- 結果是從參數列帶入, 一層一層做運算
- 如  void dfs(xxx, vector<int>& res); 其中vector<int>& res 為解果.


(*)
-由下(最深層)往上(最上層)累計, 如同post-order
-由上往下, 如同pre-order

(*)每往下一層的搜索, 對於平行層的遍歷, 必須考慮是否有重複;
如combination sum題型
for(int i=start; i<s.size(); ++i){
    if(i!=start && (s[i]==s[i-1])) continue;
    dfs(...);
其中, s[i]==s[i-1]判斷是因為, 在下一層dfs(...)的運算,已經被運算到.




}



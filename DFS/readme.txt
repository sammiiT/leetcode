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




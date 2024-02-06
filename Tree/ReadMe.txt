1.
root: 沒有父節點的節點

2.
degree:一個節點的子節點數

3. 
non-leaf(非葉子節點):有子節點的節點.
leaf(葉子節點):沒有子節點的節點.

4.
level: 絕對位址
root的level為0

    A --------------- level_0           
   / \         
  B   C ------------- level_1        
 /\   /\           
D  E F  G ----------- level_2         


距離,不算當下的位置 開始計算, 跳到目的地的count;
a  b  c  d  e  f ; a到f的距離, 不算a, 算b,c,d,e,f,總共5次count=> 5為a到f的距離

5.
Depth: 最大的level數
    A --------------- Depth_0           
   / \         
  B   C ------------- Depth_1        
 /\   /\           
D  E F  G ----------- Depth_2         


(*)Traversal(遍歷) 
pre-order   in-order    post-order    level-order
    1           2          3              1
    A           A          A              A          
   / \         / \        / \            / \
 2B   5C      B   C      B   C         2B   3C  
 / \          1   3      1   2         / \
D   E                                 D   E
3   4                                 4   5


(*)full binary tree
-所有internal node都有兩個subtree(兩個child)
-所有的leaf節點, 都有相同的level(相同的height)

    A           
   / \         
  B   C          
 /\   /\           
D  E F  G           

full-binary-tree


(*)complete binary tree
-所有的node(節點)的排列是, 由上至下, 由左至右

    A           A
   / \         / \
  B   C       B   C
 / \             / \
D   E           D   E

complete      非complete

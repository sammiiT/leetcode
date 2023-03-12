//===類似題===
1444. Number of Ways of Cutting a Pizza
1466. Reorder Routes to Make All Paths Lead to the City Zero
771. Jewels and Stones
535. Encode and Decode TinyURL
//===思路====
(*)利用unordered_map<int,vector<int>>; 紀錄"每一個節點"的"下一個路徑節點"
edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]];
[1,4],[1,5],[0,1] => 1連接4,5和0 =>4,5是1的child,0是1的root.

      0
     /
    1
   / \ 
  4   5
unordered_map<int,vector<int,int>> trees;
for(auto x:edges){
  trees[x[0]].push_back(x[1]);
  trees[x[1]].push_back(x[0]);
} 
當節點為1時, 對應的vector<int>是 {0,4,5}  
1所連結的點是{0,4,5}

(*)  
-每一個節點都是root節點, 連接root節點的都是child, 每一個child路徑,都是一種"解"的可能
-每一個child節點(如果下面有子節點)都可以是root節點(呼應上一句)
-
  
-過程中要建立一個visited[i], 防止重複拜訪 
-- "1"往回算到"0", 要將此路徑避免

- 已經visited過的,不需要pop
--

(*)每一level最後會return
- n+2 :之前(trasvers)有路過有apple的節點, 之後路徑都要+2
- 0: 路徑中如果都沒有遇到apple節點, 則之後的路徑都是+0
  
         x
       /   \
      x     o
    /  \   / \
   x    x x   o
  / \
o(@) x(@)
//===
int DFS(int node,unordered_map<int,vector<int>>& trees,vector<bool>& hasApple,unordered_map<int,int>& visited){ 
    int n = 0;
    visited[node]=1;
    for(auto x:trees[node]){
        if(visited[x]) continue;
        //n = DFS(x,trees,hasApple,visited);//path are not connected //沒有累加,最後只會回傳, 最後一個路徑的當下結果
        //continuous_path => n+=DFS(x,trees,hasApple,visited); //將過去的結果加起來, 
        n += DFS(x,trees,hasApple,visited);
    }
    //每次都找到最後一個節點...上圖中的"@"
    return (n==0 && !hasApple[node])? 0 : n+2;//n+2: 之前(trasvers)有路過有apple的節點, 之後路徑都要+2
                                              //路徑中如果都沒有遇到apple節點, 則之後的路徑都是+0
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    unordered_map<int, vector<int>> trees;
    unordered_map<int,int> visited;

    for(auto x:edges){
        trees[x[0]].push_back(x[1]);
        trees[x[1]].push_back(x[0]);
    }
    int cnt = DFS(0,trees,hasApple,visited);
    return cnt?cnt-2:0;
}


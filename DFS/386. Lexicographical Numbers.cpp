//===類似題====
387. First Unique Character in a String
1306. Jump Game III
1254. Number of Closed Islands
2096. Step-By-Step Directions From a Binary Tree Node to Another

//===思路====
(*)lexicaographical 本身是由 DFS 產生的數列 
n=200
1,10,(100,101,102,103,104,105,106,107,108,109),
  11,(110,111,112,113,114,115,116,117,118,119),
  12,(120,121,122,123,124,125,126,127,128,129)
   |   |
   |   |
   |    \
   |    (cur = (上一層cur)* 10+i) , cur=120, i=0  
    \
   進入下一個level;(cur*10+i<=n) 
    
//=====
void helper(int cur, int n, vector<int>& res){
    if(cur > n) return;
    res.push_back(cur);
    
    for(int i=0; i<=9; ++i){
        if(cur*10+i<=n){
            helper(cur*10+i, n, res);
        }else break;
    }
}

void lexicalOrder_helper(int n, vector<int>& res){
    for(int i=1; i<=9; ++i){ 
        helper(i,n,res); 
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> res;
    lexicalOrder_helper(n,res);
    return res;
}

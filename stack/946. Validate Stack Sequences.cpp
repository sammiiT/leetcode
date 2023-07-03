//===類似題===
947. Most Stones Removed with Same Row or Column
1034. Coloring A Border
803. Bricks Falling When Hit
982. Triples with Bitwise AND Equal To Zero

//===思路===
(*)用stack計算
(*)宣告一stack, 用來模擬pushed和popped的動作
1. 遍歷pushed數列, 每次都將pushed[i]推入stack中
2. 推入stack的top()同時用來跟popped做比對
-如果stack.top()==popped[j] => 則stack.pop(), 並更新popped陣列的index
-重複上述動作直到 stack.top()!=popped[j]

3.遍歷完數列之後, 如果stack.size()==0, 則popped和pushed是有效的

(*)
1.當pop時,用vector<int> res;  將其作res.push_back()操作
pop操作條件:
-當back()==popped[j]時 (j=0~n-1)
-每操作一次pop(),就對j更新一次; 先賦值;再更新

2.push操作條件:
-每次新遍歷的pushed[i],都先做一次push的操作


//=======
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();//, m = popped.size();
    int i,j;    
    stack<int> stk;
    
    for(i=0,j=0; i<n;){
        //if(i<n) stk.push(pushed[i++]);
        stk.push(pushed[i++]);
        while(!stk.empty() && (stk.top()==popped[j])){
            stk.pop();
            j++;
        }
    }
    return stk.size()?false:true;    
}
//===

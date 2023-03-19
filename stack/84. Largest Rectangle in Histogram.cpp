//===類似題===
85. Maximal Rectangle
85. Maximal Rectangle
1793. Maximum Score of a Good Subarray

//===思路===
(*)用stack計算, stack用來紀錄遍歷的index,此index是比index-1所對應的height還要大
-height[index-1]<height[index]

1.index遍歷到5, 發現比stack.top()小; 比7小
2.從stack.top()為基準點,往前計算
--圖(一):先計算面積 7*1; 計算完將此top做pop
--圖(二):下一個stack.top()是 index=3, height=5; 跟當下遍歷的index5所對應的高度相等 (如果小於,就不繼續算下去)  
--圖(二):計算面積 5(高度)x2(寬度) ; 2(寬度)是對應3和4的index ; 計算完將top做pop, 將index3 推出stack  

--圖(三):下一個stack.top()是 index=2, height=5; 跟當下遍歷的index5所對應的高度相等 (如果小於,就不繼續算下去)
--圖(三):計算面積 5(高度)x3(寬度) ; 3(寬度)是對應2,3和4的index ; 計算完將top做pop, 將index2 推出stack
--圖(三):最後將index5  push至stack中

             圖(一)                        圖(二)                         圖(三)                     圖(四)
              +---+                         +---+                          +---+                         +---+ 
              |   |                         |   |                          |   |                         |   | 
      +---+---|   |---+             +---+---| - |---+              +---+---| - |---+             +---+---|   |---+
      |   |   |   |   |             |   | / | / |   |              | / | / | / |   |             |   |   |   |   |
  +---|   |   | 7 |   |         +---|   | / | / |   |          +---| / | / | / |   |         +---|   |   |   |   |       
  |   | 5 | 5 |   | 5 |         |   | 5 | / | / | 5 |          |   | / | / | / | 5 |         | - | - | - | - | - |---+   
  | 3 |   |   |   |   |         | 3 |   | / | / |   |          | 3 | / | / | / |   |         | / | / | / | / | / | 2 |
  |   |   |   |   |   |         |   |   | / | / |   |          |   | / | / | / |   |         | / | / | / | / | / |   |
--+---+---+---+---+---+---    --+---+---+---+---+---+---     --+---+---+---+---+---+---    --+---+---+---+---+---+------
    1   2   3   4   5             1   2   3   4   5              1   2   3   4   5             1   2   3   4   5   6 
                  
 
--圖(四):index6高度是2, 與stack.top比較,此時stack.top對應的index為5,高度為5;  height[5]>=height[6] => 5>=2  
--圖(四):依照前面的計算方式, 先求出index6的面積
--圖(四):依照(一)到(三)可知, 其運算結果的height[2:5]>=5, 所以判斷index1的高度是否大於等於2
--圖(四): index1的資訊在遍歷數列的過程中會被push至stack; 若大於等於height[6],則為面積的一部分
  
(*)當, 就往回算,遍歷所有stack.top, 如果大於等於當下的height, 就算是"面積的一部分"
  
(*)heights[stk.top()]>=heights[i] => 做運算,且pop
   heights[stk.top()]<heights[i] =>做push
 ===>此stack是一個遞增stack   

//======
int largestRectangleArea(vector<int> &height) {
    int res = 0;
    stack<int> st;
    height.push_back(0);
    for(int i=0;i<height.size(); i++){
        while(!stk.empty() && height[stk.top()]>=height[i]){
            int t = stk.top();stk.pop();
            res = max(res,height[t]*(stk.empty()?i:(i-stk.top()-1)));
        }
        st.push(i);
    }
    return res;
}

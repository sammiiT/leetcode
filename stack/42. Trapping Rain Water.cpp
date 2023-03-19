//===類似題===
43. Multiply Strings
407. Trapping Rain Water II
755. Pour Water

//===思路====
(*)用stack計算
1.遍歷數列,若height[i]比前一個高度height[i-1]小; 則將height[i]推入stack中; stack中的元素是遞減
2.遇到height[i]>前一height[stack.top()], 則開始計算"容積"
--產生容積的條件是"至少有三個index", 如果只有兩個index, 沒辦法產生容積

  
//====
int trap(vector<int>& height) {
    int res = 0;
    stack<int> stk;
    for(int i=0;i<height.size();i++){
        while(!stk.empty()&& height[stk.top()]<=height[i]){
            int t = stk.top();stk.pop();
            if(stk.size())
                res+=(min(height[stk.top()],height[i])-height[t])*(i-stk.top()-1);//比較左邊界和右邊界,取小的那一邊做(高)計算
        }                                                       //i-stk.top()-1; 減1的目的是不將當下的位置算進去,只算左邊界和右邊界的距離
        stk.push(i);
    }
    return res;
}

//===類似題===
156. Binary Tree Upside Down
239. Sliding Window Maximum
716. Max Stack

//===思路===
(*)兩stak, 定義 stk1和stk2; 
-stk1是依據推入順序推入
-stk2是存入minimum; 最上面(top)的數值, 是最小的值 

(*)stk2會排除其他min區間的數; 
1.

//=====
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if(stk2.empty() || stk2.top()>=val) stk2.push(val);
        stk1.push(val);
    }
    
    void pop() {
        if(stk2.top()==stk1.top()) stk2.pop();
        stk1.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
private:
    stack<int> stk1,stk2;
};

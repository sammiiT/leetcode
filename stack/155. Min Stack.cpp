//===類似題===
156. Binary Tree Upside Down
239. Sliding Window Maximum
716. Max Stack

//===思路===
(*)兩stak, 定義 stk1和stk2; 
-stk1是依據推入順序推入
-stk2是存入minimum; 最上面(top)的數值, 是最小的值 

(*)stk2會排除其他min區間的數; 有min(x,y)的概念=>排除其他的數
1.如果用priority_queue會記錄到每一個數值, 求算起來

for(int i=0;i<nums;i++){
    res = min(res,nums[i]); //區間n~i 之間, 最小的數值
                            //res是0~n區間, 最小的數值
}
stk2的概念與min概念一樣: 
- stk2有紀錄每一個區間的最小數值, 
- min(x,y)是會排除前面區間最小的數值

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

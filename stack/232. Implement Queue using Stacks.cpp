//===類似題====
233. Number of Digit One
705. Design HashSet
2030. Smallest K-Length Subsequence With Occurrences of a Letter
321. Create Maximum Number
//===思路===

//=====
class MyQueue {
public:
    MyQueue() {}
    void push(int x) { stk.push(x);}
    int pop() {//remove
        int ret;
        while(stk.size()>1){//將stk中的element放到stmp中, 剩一個做為queue front
            stmp.push(stk.top());
            stk.pop();        
        }
        ret = stk.top();//設定回傳數值
        stk.pop();//將數值移除
        while(!stmp.empty()){//將temp中的element移回stk
            stk.push(stmp.top());
            stmp.pop();
        }
        return ret;//回傳數值
    }
    int peek() {//front
        int ret;
        while(stk.size()>1){//將stk中的element放到stmp中, 剩一個做為queue front
            stmp.push(stk.top());
            stk.pop();
        }
        ret = stk.top();//
        while(!stmp.empty()){//將temp中的element移回stk
            stk.push(stmp.top());
            stmp.pop();
        }
        return ret;回傳數值
    }
    bool empty() { return stk.empty(); }
private:
    stack<int> stk;
    stack<int> stmp;
};

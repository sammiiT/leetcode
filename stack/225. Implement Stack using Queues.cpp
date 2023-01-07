//===類似題====
226. Invert Binary Tree
232. Implement Queue using Stacks
//===思路===

//=====
class MyStack {
public:
    MyStack() {}
    void push(int x) { q.push(x); }
    int pop() {
        int ret;
        while(q.size()>1){//將q pop到temp q, 剩下一個
            qt.push(q.front());
            q.pop();
        }
        ret = q.front();//回傳最後一個
        q.pop();
        while(!qt.empty()){//將temp_q的element,放回q
            q.push(qt.front());
            qt.pop();
        }
        return ret;
    }
    int top() { return q.back(); }
    bool empty() { return q.empty();}
private:
    queue<int> q;
    queue<int> qt;
};
//======其他人解法=====
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {}
    void push(int x) {
        if(q1.empty())
            q1.push(x);
        else{
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    int pop() {
        int temp= q1.front();
        q1.pop();
        return temp;
    }
    int top() { return q1.front(); }
    bool empty() { return q1.empty();}
};

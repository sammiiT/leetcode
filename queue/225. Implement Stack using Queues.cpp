//===類似題===
226. Invert Binary Tree
211. Design Add and Search Words Data Structure
1500. Design a File Sharing System
173. Binary Search Tree Iterator
//===思路===

//====
class MyStack {
public:
    MyStack() {
    }
    void push(int x) {
        q.push(x);
    }
    int pop() {
        int ret;
        while(q.size()>1){
            qt.push(q.front());
            q.pop();
        }
        ret = q.front();
        q.pop();
        while(!qt.empty()){
            q.push(qt.front());
            qt.pop();
        }
        return ret;
    }
    int top() {
        return q.back();        
    }
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
    queue<int> qt;
};

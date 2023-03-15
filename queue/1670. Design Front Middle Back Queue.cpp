//===類似題===
1628. Design an Expression Tree With Evaluate Function
641. Design Circular Deque
622. Design Circular Queue
//=== 思路====
(*)插入位置
-偶數插中間;計算出first middle 再加1
(size-1)/2 + !(size%2)

-奇數插在first middle, 計算出first middle, 


//=====
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        q.clear();
    }
    
    void pushFront(int val) {
        q.insert(q.begin(),val);
    }
    
    void pushMiddle(int val) {
        int size = q.size();
        if(!size) {q.push_back(val); return;}
        int in = (size-1)/2 + !(size%2);
        q.insert(q.begin()+in,val);
    }
    
    void pushBack(int val) {
        q.push_back(val);
    }
    
    int popFront() {
        if(q.empty()) return -1;
        int res = q[0];
        q.erase(q.begin());
        return res;
    }
    
    int popMiddle() {
        if(q.empty()) return -1;
        int outm = (q.size()-1)/2;
        int res = q[outm];
        q.erase(q.begin()+outm);
        return res;
    }
    
    int popBack() {
        if(q.empty()) return -1;
        int res = q.back();
        q.pop_back();
        return res;
    }
private:
    vector<int> q;
};



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

//===思路2====
(*)討論push_middle
-如果是奇數個, 要加入到 first_middle; 以0-index來算
O O O  => first_middle  ((size-1)-0)/2 => (size-1)/2

-如果是偶數個, 要加到 second_middle; 以0-index來算
O O O O => second_middle  ((size-1)-0+1)/2 => size/2

(*)討論pop_middle
-如果是奇數個, 要移除 first_middle; 以0-index來算
O O O  (size-1)/2

-如果是偶數個, 要移除 first_middle; 以0-index來算
O O O O (size-1)/2

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        q.clear();
    }
    void pushFront(int val) {
        q.insert(q.begin(),val);
    }
    void pushMiddle(int val) {
        int n = q.size();
        if(n==0) {q.push_back(val); return;}    
        if(n%2){//odd
            q.insert(q.begin()+(n-1)/2,val);
        }else{//even 
    	    q.insert(q.begin()+n/2,val);
        }
    }
    void pushBack(int val) {
        q.push_back(val);
    }
    int popFront() {
        int n = q.size();
        if(n==0) return -1;
        int f = q[0];
        q.erase(q.begin());
        return f; 
    }
    int popMiddle() {
        int m,n=q.size();
        if(n==0) return -1;
        m=q[(n-1)/2];
        q.erase(q.begin()+(n-1)/2);
        return m;
    }
    int popBack() {
        int n = q.size();
        if(n==0) return -1;
        int b = q.back();
        q.pop_back();
        return b;
    }
private:
    vector<int> q;
};



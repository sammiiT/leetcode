//===類似題===
1846. Maximum Element After Decreasing and Rearranging
379. Design Phone Directory
2349. Design a Number Container System
//===思路===
(*)
 宣告 priority_queue<int,vector<int>,cmp>, 排列ascending

(*)每次reserve(),就從priority_queue中pop()出一個元素, 此元素為minimum
(*)每次unreserve(int), 就將數值push()回priority_queue

//=====
class SeatManager {
public:
    SeatManager(int n) {
        for(int i=1; i<=n; ++i) pq.push(i);
    }
    
    int reserve() {
        int ret = pq.top();
        pq.pop();
        return ret;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
private:
static struct cmp{
    bool operator()(int& a,int& b){
        return a>b;
    }
};
priority_queue<int,vector<int>,cmp> pq;

};


//====用 stack做 會造成 Time Limited Exceeded ===
{
SeatManager(int n) {
        for(int i=n; i>0; --i) stk.push(i);
    }
    int reserve() {
        int ret = stk.top();
        stk.pop();
        return ret;
    
    void unreserve(int seatNumber) {
        while(!stk.empty() && stk.top()<seatNumber){
            ustk.push(stk.top());
            stk.pop();
        }
        stk.push(seatNumber);

        while(!ustk.empty()){
            stk.push(ustk.top());
            ustk.pop();    
        }        
    }
private:
stack<int> stk;
stack<int> ustk; 
}


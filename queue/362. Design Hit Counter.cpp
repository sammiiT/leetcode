//===類似題===

//===思路===
(*)用queue
1. 用queue存入每一個timestamp
2. getHits呼叫, 將中pop的timestamp與getHits的timestamp 取差值; 並依據題意:
如果>=300, 則pop Q中的first; 一直到滿足<300的條件為止 
如果<300, 則取Q的size 

3.在empty之前滿足題意, 回傳hit counter; 反之,回傳0

//=====
class HitCounter{
public:
    HitCounter() {}
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        int hits = 0;
        while(!q.empty()){
            if(timestamp-q.front()<300){
                hits = q.size();
                break;
            } else{//>=300
                q.pop();
            }
        }
        return hits;
    }
private:
    queue<int> q;
};

//====解2 ;同上述概念 ====
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {}
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= 300) {
            q.pop();
        }
        return q.size();
    }
private:
    queue<int> q;
};

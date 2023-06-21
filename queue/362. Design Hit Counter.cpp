//===類似題===


//===思路1===
(*) count hit in the past 5 minutes, 表示, 差距300要重新計算
- 1~301=>差距300
- 0~300=>差距299
- 300~600=>差距300

從1開始,所以是1-index ; 1~10算一個part
從0開始, 0-index; 0~9算一個part
    
(*) q.front()與timestamp差距為300時, 執行q.pop();
(*) 在hit()中, 判斷上述, 最後執行q.push(timestamp); 
(*) 在getHits()中, 判斷上述, 最後執行返回q.size();

class HitCounter {
public:
/*
0-index: 0~9     0~299
1-index: 1~10    1~300 ==>*/
    HitCounter() {}
    void hit(int timestamp) {
        while(!q.empty()){
            if(timestamp-q.front()>=300) q.pop();
            else break;
        }
        q.push(timestamp);
    }
    int getHits(int timestamp) {
        while(!q.empty()){
            if(timestamp-q.front()>=300) q.pop();
            else break;
        }
        return q.size();
        
    }
private:
    queue<int> q;
};




//===思路2=== 用思路1比較好
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

//===類似題===
902. Numbers At Most N Given Digit Set
739. Daily Temperatures
//===思路===
(*)用stack解題(利用vector模擬stack動作)
- vector<pair<int,int>> //price, count; count是大於之前數值的個數

(*)
1. 如果當天price沒有大於前一天, 則push至stack,並將count計為1
stk.push_back(make_pair(price,1));
2.如果當天的price大於前一天, 則將stack.top() 推出, 並將其count累加至當天的count;
-並循環計算是否在前一天也小於當天price, 如果是, 則同樣執行上一個描述; 一直到top()的price大於當天
-最後累加的count,和price 推入stack

(*)consecutive 連續的=> 題目求的是連續的subarry, 中間不能中斷
- [60, 90, 60, 80] =>  80往前比較, 到90就停下來 

(*)consecutive common  sequeunce => 序列可以中斷, 但order不變 
//=======
class StockSpanner {
public:
    StockSpanner() {
    }
    int next(int price) {
        int res = 0;
        if(stk.empty()) {
            stk.push_back(make_pair(price,1)); 
            return 1;
        }        
        while(!stk.empty() && (stk.back().first<=price)){
            res+=stk.back().second;
            stk.pop_back();
        }
        stk.push_back(make_pair(price,res+1));
        return res+1;
    }
private:
vector<pair<int,int>> stk;//price, count

};
//=====
class StockSpanner {
public:
    StockSpanner() {
        stk.push_back(make_pair(INT_MAX,0));
    }
    
    int next(int price) {
        int res = 0;        
        while(!stk.empty() && (stk.back().first<=price)){
            res+=stk.back().second;
            stk.pop_back();
        }
        stk.push_back(make_pair(price,res+1));
        return res+1;
    }

private:
vector<pair<int,int>> stk;//price, count

};

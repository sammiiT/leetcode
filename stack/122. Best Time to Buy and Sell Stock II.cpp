//===類似題===
123. Best Time to Buy and Sell Stock III
123. Best Time to Buy and Sell Stock III
188. Best Time to Buy and Sell Stock IV
309. Best Time to Buy and Sell Stock with Cooldown

//===思路===
(*)用Stack資料結構
//====
    int helper0(vector<int>& prices) {
        stack<int> stk;
        int res = 0;
        for(int i=0; i<prices.size(); i++){
            if(stk.empty()|| stk.top()>=prices[i]){
                stk.push(prices[i]);
            }else{//stk.top()<prices
                res+=prices[i]-stk.top();
                stk.push(prices[i]);
            }
        }
        return res;
    }

int helper1(vector<int>& prices) {
    stack<int> stk;
    int res = 0;
    stk.push(prices[0]);
    for(int i=1; i<prices.size(); i++ ){
        if(stk.top()<prices[i]){ res+=prices[i]-stk.top(); }
        stk.push(prices[i]);
    }
    return res;
}

int maxProfit(vector<int>& prices) {
    return helper1(prices);
}    

//=====思路2
(*)in-place計算, 當下數值比前一個數值
int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i=1;i<prices.size();++i){
            int tmp = prices[i]-prices[i-1];
            //res = res + tmp>0 ? tmp:0;
            if(tmp>0) res+=tmp;
        }
        return res;
 }

//===類似題===
123. Best Time to Buy and Sell Stock III
123. Best Time to Buy and Sell Stock III
188. Best Time to Buy and Sell Stock IV
309. Best Time to Buy and Sell Stock with Cooldown
//===思路===
(*)遍歷數列
1.紀錄min的數值
2.依序將每一個prices[i]減去min數值, 並取max(x,y); 即為解
//====
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int res = INT_MIN;
        int b = prices[0];
        for(int i=0;i<prices.size();++i){
            b = min(b,prices[i]);
            res = max(res,prices[i]-b);
        }
        return res;
            
    }
};

int maxProfit(vector<int>& prices) {
    int res = 0;
    int day_min = INT_MAX;
    for(int i=0;i<prices.size();++i){
        day_min = min(day_min,prices[i]);
        res = max(res,prices[i]-day_miin);
    }
    return res;
}

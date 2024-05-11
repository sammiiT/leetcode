
//===思路===
(*)遍歷數列
-紀錄最小的值
-將遍歷的數值減去最小的值, 最大的差,即為解

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

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
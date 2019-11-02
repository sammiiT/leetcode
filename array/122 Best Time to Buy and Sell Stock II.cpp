class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i=1;i<prices.size();++i){
            int tmp = prices[i]-prices[i-1];
            //res = res + tmp>0 ? tmp:0;
            if(tmp>0) res+=tmp;
        }
        return res;
    }
};
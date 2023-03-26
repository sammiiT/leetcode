//===類似題====
715. Range Module
2144. Minimum Cost of Buying Candies With Discount
245. Shortest Word Distance III
562. Longest Line of Consecutive One in Matrix
//===思路=====
(*) dynamic programming
- 當下 只與之前相關  => s[i] = (s[i-1])
- 當下 與之前相關, 且與當下相關 => s[i] = (s[i-1],s[i])

(*)兩個陣列, 一個是賣出利潤sold[i],一個是買入損失 hold[i]  
  
1.今天賣出去的利潤 
= 之前買入(損失的錢) + 今日賣出的單價 - 交易費
= hold[i-1] + prices[i] - fee
  
2.今天買入所得到的利潤和
= 過去賣出的利潤 + 今日買入的花費
= sold[i] - prices[i]

3.每次比較當天的買入的花費和賣出的利潤
買入: 花越少錢越好
賣出: 越多錢越好

sold[i]= max(sold[i-1],hold[i-1]+prices[i]-fee);
hold[i]= max(hold[i-1],sold[i-1]-prices[i]);

//======

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> sold(n,0);
    vector<int> hold(n,0);

    hold[0]=-prices[0];

    for(int i=1; i<n; ++i){
        sold[i]=max(sold[i-1],hold[i-1]+prices[i]-fee);
        hold[i]=max(hold[i-1],sold[i-1]-prices[i]);
    }
    return sold.back();
}

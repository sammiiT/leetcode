//===類似題===
92. Reverse Linked List II
639. Decode Ways II
1977. Number of Ways to Separate Numbers
2266. Count Number of Texts

//===思路===
(*)dynamic_programming
(*)非in-place計算, 需要建立一新的"解",從原本的string來判斷求解
(*)dp[i]=(s[i-1]=='0')?0:dp[i-1];
-[i]是經過[i-1]之後的結果, 但尚未將[i]考慮進去  ====> 利用此口絕來做題
-dp[i]=>新建, dp[i]有初始值,此初始值由"題意,數列結構"決定
--dp[0]=1, 前一個數值為1, 則有1種解
-s[i-1]=>原數值

//=====
class Solution {
public:
    int numDecodings(string s) {
        
                    //第一個數不能等於"0"     
        if(s.empty()||s[0]=='0') return 0;
        
        
        vector<int> dp(s.size()+1,0);
        
        dp[0] = 1;//預設值
/*
dp[1]會運算到 s[0] dp[0]
dp[2]會運算到 s[1] dp[1]
dp[3]會運算到 s[2] dp[2]
dp[4]會運算到 s[3] dp[3]
*/
        
        for(int i=1; i<dp.size(); ++i){//從"1"開始, "0"為預設初始值
                            //(現在dp[i-1]會等於0,因為下敘述判斷式)   
//多了下面條件, 與之前的 "一定有數值"不同 dp[i]=dp[i-1]+dp[i-2];  
            dp[i]=(s[i-1]=='0')?0 : dp[i-1];//不同的輸入,會有不同的dp對映
            
            if(i>1 && (s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<='6'))){
/*
i=3
0 1 2
1 1 2       1 1 0
1,1,2       1 10
11,2        11
1,12

*/
                
                dp[i]+=dp[i-2];
            }
        }
        return dp.back();
        
    }
};

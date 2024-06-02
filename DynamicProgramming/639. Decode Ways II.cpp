//=== more challenge ===
1977. Number of Ways to Separate Numbers
2147. Number of Ways to Divide a Long Corridor

//=== 思路 ====
(*) dynamic programming
- 如果建立的dp size比原陣列多一個元素
=> 當下索引(k)的dp update, 會記錄在dp索引(k+1)位置上  
=> 當下的 位置用(i-i)表示, 所以當下的dp會記錄在 比原位置(i-1)多一的位置; 也就是 dp[i]= f(i-1);
=> 在dp udpate的運算上; 如下:
for(int i=1; i<=n; ++i)
  if(s[i-1]==t)
  dp[i] = dp[i-1]+1;
     \       \- s[i-2]對應的dp_update; s[i-2]屬於前一個位置   
     s[i-1]對應的dp_update; s[i-1]屬於當下位置 

(*)討論:
當下為0:
-只能跟前一個數做合併
-前一個數為1~9=>只能取1,2
dp[i] = dp[i] + dp[i-2];
-前一個數為* => 只能取(1,2)合併, (3,4,5,6,7,8,9)是屬於不能合併
dp[i] = dp[i] + 2*dp[i-2]; 
  
-非上述 => 回傳0
  
當下為數值1~9:
-可以與前一個數值做拆分
dp[i]=dp[i]+dp[i-1];
-可以與前一個數做合併
--如果前一個數值為1或2
如果s[i-2]=='1'
dp[i] = dp[i] + dp[i-2];  
如果s[i-2]=='2' && s[i-1]<='6'
dp[i] = dp[i] + dp[i-2]
  
--如果前一個數值為*
dp[i]=dp[i] + (s[i-1]<='6')?(2*dp[i-2]):dp[i-2];
                            *是1,2       *是1
當下為*:
-可與前一個數值做拆分
dp[i]=dp[i]+dp[i-1]*9
-可與前一個數值做合併
--如果前面為1或2
前面為1:
dp[i] = dp[i]+9*dp[i-2];      
前面為2:
dp[i] = dp[i]+6*dp[i-2];

--如果前面是為*
dp[i] = dp[i] + 15* dp[i-2];                              
  
int numDecodings(string s) {
    int n = s.size();
   int M = 1e9+7;
   vector<long> dp(n+1,0);
   dp[0]=1;
   if(s[0]=='0') return 0;
   if(s[0]=='*') dp[1] = 9;
   else // s[0]=1~9
    dp[1] = 1;

    for(int i=2; i<=n; ++i){
        if(s[i-1]=='0'){
            if(s[i-2]=='1'||s[i-2]=='2'){
                dp[i] = dp[i] + dp[i-2];
            }else if(s[i-2]=='*'){
                dp[i] = dp[i] + 2* dp[i-2];    
            } else {//s[i-2]=='0'
                return 0;
            }
        }else if(s[i-1]>='1' && s[i-1]<='9'){
            dp[i] = dp[i] + dp[i-1];
            if(s[i-2]=='1'){
                dp[i] = dp[i] + dp[i-2];        
            }else if(s[i-2]=='2'&& s[i-1]<='6'){
                dp[i] = dp[i] + dp[i-2];
            }else if(s[i-2]=='*'){
                if(s[i-1]<='6') dp[i] = dp[i] + 2*dp[i-2];
                else dp[i] = dp[i] +dp[i-2];
            }

        } else {
        //else if(s[i-1]=='*'){
            dp[i] = dp[i]+9*dp[i-1];
            if(s[i-2]=='1'){
                dp[i] = dp[i] + 9*dp[i-2];
            }else if(s[i-2]=='2'){
                dp[i] = dp[i] + 6*dp[i-2];
            }else if(s[i-2]=='*'){
                dp[i] = dp[i] + 15*dp[i-2];    
            }
        }
        dp[i]%=M;
    }
    return dp[n]; 
}

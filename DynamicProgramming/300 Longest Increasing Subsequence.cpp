//===類似題===
354. Russian Doll Envelopes
673. Number of Longest Increasing Subsequence
712. Minimum ASCII Delete Sum for Two Strings
//===思路===
(*) dynamic programming

dp[i]  物理意義, index從(0~i) 共有幾個value是increase
dp[i]=max(dp[i],dp[j]+1)    // (+1)物理意義: 第i個數值,要+1


ex:
    0   1   2   3   4
    1,  2,  3,  4,  5

i=0;
dp[1]=max(dp[1],dp[0]+1) =  1+1 =2

i=2;
dp[2] .... dp[0],dp[1]

dp[2]=dp[0]+1 =2 
dp[2]=dp[1]+1 =2+1=3

i=3;
dp[3] .... dp[0],dp[1],dp[2] 
dp[3] = dp[0]+1 
dp[3] = dp[1]+1
dp[3] = dp[2]+1 = 4

//=====
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        vector<int> dp(nums.size(),1);
        int res=0;
  
/*
                i   //固定i
          j         //每次j的變化,會重新改變dp[i]的值
    1, 2, 3, 4, 5...
*/        
        
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i]){
                                        //"+1"加上當下nums[i]的個數    
                    dp[i]=max(dp[i], dp[j] + 1);
                }
            }
            res = max(res,dp[i]);
        }
/*        
max,和min解釋
1.紀錄之前的極值(極大或極小) => 如上面描述的res (舊的)
2.更改極值(極大或極小) => 如上面描述的y (新的)
*/        
        return res;
    }
};

//=== 思路解析 =====
(*)用一維的方式思考
- 每一輪 到第i個索引, increasing sequence的個數

i=  0   1   2   3   4   5   6
    a   b   c   d   e   f   g

- i=2時, 計算[0:2]的increasing sequence的個數, 就是dp[2], 此dp[2]會給下一輪 i=3,i=4...做參考


- 過程中, 若不滿足提議;如 [4]<[3]; 則不列入計算, 如下:
  
    [0] [1] [2] [3] [4] [5] [6]  
    1    2   3   9   5   6   7
        
第(i=4)輪,因[4]<[3], 所以真正列入計算的是  [0][1][2][4]
    [0] [1] [2] ... [4]


用1維思考, 會牽涉到prefix sum的概念:
- res = max(res, dp[i]);
- 這樣內部運算就會包含了 "中間段"的結果
- "中間段",不從"0"開始的subarray; 如[1:5],[3:7]...

- dp[i]=max(dp[i],dp[j]+1)//其中+1是 [i]的本身
                    \    \
                     \    nums[i]本身
                   前面的累計increasing sequence數目


(*)用2維的方式思考, dp[i][j]概念會誤會成 第[i:j] 的increasing subsequnce.
- 如何用2維方式計算(思考), 得到對應的解???

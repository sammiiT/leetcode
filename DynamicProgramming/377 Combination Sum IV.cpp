//===類似題===
1286. Iterator for Combination
2787. Ways to Express an Integer as Sum of Powers
//===思路===
(*)思路可以參考 climbing stairs
(*)dp[i] = 個數
(*)數列從 [1~target] 分別做比較
- [1~target]每一個數字 與 nums[i]做比較, 當[1~target]數值比nums[i]大,則

for(int i=1;i<=target;++i){
    for(int a:nums) { 
        //每一個target與
        if(i>=a) dp[i] = dp[i] + dp[i-a];
                   |        |       |
                   |        |       \ 
                   |    之前的個數    當下差值所對應個數(屬於之前的個數) 
             taret所對應的新個個數
    }    
}

(*)思路可以參考 climbing stairs
vector<unsigned int> dp(target+1);
- i = 加總等於"i"; i=2 加總等於2, i=5 加總等於5
- dp[i] = 出現加總等於"i"的個數    
dp[0] :加總等於0的個數  dp[0]一定等於1, 因為是作為dp[1:5]的初始值, 第一次發生一定都跟dp[0]有關(相差值)
dp[1] :加總等於1的個數
dp[2] :加總等於2的個數
dp[3] :加總等於3的個數
dp[4] :加總等於4的個數
dp[5] :加總等於5的個數

(*)
[1,2,3] target=2
(1,1)
(2)
dp[1]=dp[1]+dp[1-1] = 0+1 = 1

dp[2]=dp[2]+dp[2-1] = dp[2]+dp[1] = 0+1 = 1
dp[2]=dp[2]+dp[2-2] = dp[2]+dp[0]=  1+1 = 2
        |       |
         \       \
       相差1      相差0

(*)若求加總等於5的個數:
dp[5]=dp[5]+dp[5-a] = dp[5]+dp[5-1] = dp[5]+dp[4]
                                               |-> a已經等於1了,所以剩下4;求總和等於4的個數   
                                               
dp[5]=dp[5]+dp[5-a] = dp[5]+dp[5-2] = dp[5]+dp[3]
                                               |-> a已經等於2了,所以剩下3;求總和等於3的個數

dp[5]=dp[5]+dp[5-a] = dp[5]+dp[5-3] = dp[5]+dp[2]
                                               |-> a已經等於3了,所以剩下2;求總和等於2的個數

總和為3可以拆分為如下;其中x為陣列的元素值
1+x =>求出dp[1]的個數 
2+x =>求出dp[2]的個數
3+x =>求出dp[0]的個數

//===
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target){
        // vector<int> dp(target + 1);//錯誤
       
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i >= a) dp[i] += dp[i - a];
            }
        }
        return dp.back();
        
//         vector<int> dp(target+1,0);
        
//         dp[0]=1;//why??
//         for(int i=1; i<=target; ++i){
//             for(auto a:nums){
//                 // if(i>=a) dp[i] = dp[i]+dp[i-a];
//                 if (i >= a) dp[i] += dp[i - a];
//             }
//         }
//         return dp.back();
    }
};

#=== 寫法2====
(*)dfs + mem
利用 dfs+ mem的概念可以反推 dynamic programing的寫法

if(mem[target-sum]!=-1) return mem[target-sum];# dp[sum] = dp[sum]+dp[target-sum];
count = dfs(nums,target,sum+nums[i],mem) #

=> 可以想像成
dp[i]=dp[i]+dp[i-a]
dfs是會算到最底層
dp是一開始從最底層開始疊加

int dfs(vector<int>& nums, int target, int sum, vector<int>& mem){
    if(sum>target) return 0;
    if(sum==target) return 1;
    if(mem[target-sum]!=-1) return mem[target-sum];

    int count = 0;
    for(int i=0;i<nums.size();++i){
        int ret = dfs(nums,target,sum+nums[i],mem);
        count+=ret;
    }
    mem[target-sum]=count;
    return count;

}
int combinationSum4(vector<int>& nums, int target) {
    vector<int> mem(target+1,-1);
    return dfs(nums,target,0,mem);        
}

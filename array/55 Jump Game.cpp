//=====相似題======
56. Merge Intervals
45. Jump Game II
1306. Jump Game III
1871. Jump Game VII
//===思路===
(*)每一次運算都必須判斷前一次的jump數目,如果放到迴圈外才做判斷,會錯誤
-前一個jump,是否能到達i的位址,
-減1目的是,前面剩下的jump數目, 是否能到i位置
dp[i]=max(dp[i-1],nums[i-1])-1;

(*)下面算法會錯誤,因為沒辦法判斷中途的jump數,是否能不能到達下一個位址
for(int i=1; i<nums.size(); i++)
    dp[i]=max(dp[i-1],nums[i-1])-1;
return dp[n-1]>=0?true:false;
//====
bool helper0(vector<int>& nums) {
    vector<int> dp(nums.size(),0);
    dp[0]=nums[0];
    for(int i=1; i<nums.size(); i++){
        dp[i]=max(dp[i-1],nums[i-1])-1;
        //if(dp[i]==0 && i<nums.size()-1){
        if(dp[i]<0){//再每一次計算中都必須判斷, 前一次的jump是否能到達第i個位址
            return false;
        }            
    }
    return true;
}

//====
class Solution {
public:
    bool canJump(vector<int>& nums) {
//---FAIL--------
//         int n = nums.size();
//         int ret = false;
//         int jump = 0;
//         if(n==1) return true;
//         for(int i = 0; i<n; ){//i = n-1還是會再執行一次
//             jump = nums[i];           
//             if(jump==n-1){
//                 ret = true;
//                 break;
//             }else if(jump == 0){
//                 ret = false;
//                 break;
//             }else{
//                 // i = jump;                
//             }
//             i= i + jump;
//         }
//         return ret;

//--FAIL--------此方式用 [2,5,0,0] 會有錯誤輸出---------//  
//----------因為只考率最大輸出, 沒考慮從小到大的其他輸出-----        
        // int n = nums.size();
        // int ret = false;
        // int jump = 0;        
        // for(int i=0; i<n;){
        //     jump = nums[i];
        //     if(jump>=n-1){
        //         ret = true;
        //         break;
        //     }else if(jump==0){
        //         ret = false;
        //         break;
        //     }
        //     i = i+jump;//next index
        // }
        // return ret;
//------------------------------------------
        
/*
    第一個點到終點的跨步是否會大於等於終點位置
    第二個點到終點的跨步是否會大於等於終點位置  
    ...etc
*/        
        int n= nums.size();
        int remain;
        int ret=false;
        // for(int i = 0; i<n; ++i){
        //     remain = (n-1)-i;
        //     //[3,2,1,0,4]會有錯誤
        //     // if(nums[i]>=remain){
        //     //     ret = true;
        //     //     break;
        //     // }
        //     //[3,2,2,0,4]--->true
        // }
        
        // //[3,0,0,1]會有錯誤結果
        // for(int i=1;i<n;++i){
        //     if(nums[i]==0){
        //         if(nums[i-1]>1) continue;
        //         else return false;
        //     }
        // }
        // return true;       
    
        
        
        
//-----當下的點跟前一個點有關....用dynamic programming        
//-----current位置與previous的為只有關, 用dynamic programming
//dp[i]是到達過去nums[k];過去某一點的剩餘步數        
//dp方法計算,必須知道初始值,初始值設定為"0"
        vector<int> dp(nums.size(),0);//
        
        // dp[i]=max(dp[i-1],nums[i-1])-1;
        for(int i = 1;i<nums.size();++i){
            dp[i]=max(dp[i-1],nums[i-1])-1;
    //max(nums[i-1],dp[i-1]):比較步伐(nums[i-1])比之前"剩下"的步伐(dp[i-1])還要多
            //"-1"表是從前一個點跳到現在的點, 所以要"-1"
            
            
            if(dp[i]<0) return false;//如果dp[i]小於"0", 則永遠到不了
                                     //(dp[i]==0),時就是依賴nums[i]來繼續往前進
        }
        return true;
    }
};


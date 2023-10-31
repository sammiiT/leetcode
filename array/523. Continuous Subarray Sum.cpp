//====類似題=====
2121. Intervals Between Identical Elements
524. Longest Word in Dictionary through Deleting
//====思路===
(*)
subarray:數值連續, 不可分割
  
(*)概念1
(a + b + c)%k == (a%k + b%k + c%k)

(*)概念2
index     0  1  2   3  4   5   6
sum_rem   3  2  7   5  4   2   1
             |              \
             \               餘2   
              餘2
              
index5_sum - index1_sum ==0 ; 
sum[1:5] 可以整除 k             
              
//=====
//return bool=> 只要發生, 就會回傳, 就算有其他解, 也不用管 =>所以只討論發生的第一次.
//=>如 m[sum]有很多發生的次數, 所以只討論發生的第一次...

//若數字a和b分別除以數字c, 若得到的餘數相同, 那(a-b)必定能整除c
bool helper3(vector<int>& nums, int k){
        unordered_map<int,int> m;
        int sum = 0;
        m[0]=-1;//沒有這項會出錯; 如果過程中就有整除的情況
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            sum%=k;
            if(m.count(sum)){//除完之後有餘數相等,則在index_(i) - index_(m-at(sum))的數值一定能整除c
                if(i-m.at(sum)>1) return true;       
            }else{
                m[sum]=i;
            }
        }
        return false;
}

bool checkSubarraySum(vector<int>& nums, int k) {
         return helper3(nums,k);
}    

//===思路2====
(*) 可以整除k, 餘數等於0
-如果有餘數, 則記錄至unordered_map<int,int>  (餘數,索引)
-當遍歷累加的總合, 若有餘數, 則判斷前面的總合是否有"相同的餘數"
-相同餘數的兩個總合的相減, 則剩下的數值就可以整除k => 此sub數列就可整除K
  
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> ump;
    int sum = 0;

    for(int i=0; i<nums.size(); ++i){
        sum = sum + nums[i];
        if((sum%k==0) && i>=1) return true;

        int remain = sum%k;
        if(ump.count(remain)){
            if(i-ump[remain]>=2) return true;
        } else {
            ump[remain] = i;
        }
    }
    return false;
}


//============ time limit exceeded ==============
    bool helper0(vector<int>& nums, int k){//time limit exceed
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0; i<n; i++){
            dp[i][i]=nums[i];//boundary
            for(int j=i+1; j<n;j++){
                dp[i][j]=dp[i][j-1]+nums[j];
                if(dp[i][j]%k==0) return true;        
            }
        }
        return false;
    }

    bool helper1(vector<int>& nums, int k){//time limit exceeded
        int n = nums.size();
        for(int i= 0; i<n; i++){
            int sum = nums[i];
            for(int j=i+1; j<n; j++){
                sum +=nums[j];
                if(sum%k==0) return true;    
            }
        }
        return false;
    }
      

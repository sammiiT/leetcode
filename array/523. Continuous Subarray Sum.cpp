//====類似題=====
2121. Intervals Between Identical Elements
524. Longest Word in Dictionary through Deleting

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
      

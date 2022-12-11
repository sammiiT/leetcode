


int helper(vector<int>& nums, int space){
  
//  unordered_map<int,int> mp
  unordered_map<int,int> remain;
//  int remCnt=0, res;
  int res;
  
  sort(nums.begin(),nums.end());
  
  for(int i=nums.size()-1; i>=0; i--){
    int val = nums[i]%space;
    remain[val]++; //remain highest
//    mp[nums[i]]++; //value smallest
    
    if(++remain[val]>=remCnt){
      remCnt= remain[val];
      res = nums[i];
    }
  }
  return res;
}


//========== 錯誤算法 ==========
int helper(vector<int>& nums, int space){
        int mxCnt = 0;
        int res;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        res = nums[n-1];
        
        if(res < space){
            unordered_map<int,int> m;
            for(int i=n-1; i>=0; i--){//找最多的那一個, 找最小的那一個
                if((++m[nums[i]])>=mxCnt){//用等於,在發生比較小的index, 可以把較大的index覆蓋
                    mxCnt = m[nums[i]];//新的max count
                    res = nums[i];
                }
            }
            return res;
        }

        for(int i=n-1;i>=0;i--){
            int cnt=0;
            for(int j=i+1; j<n; j++){
                if(nums[j]-nums[i]==space){ cnt++; }        
            }
            if(cnt>=mxCnt){
                mxCnt=cnt;
                res=nums[i];//找比較小的那一個
            }
        }
        return res;
}

//==== more challenge ===
416. Partition Equal Subset Sum
2305. Fair Distribution of Cookies
2025. Maximum Number of Ways to Partition an Array

//===思路1===
(*)time limited exceeded
(*)dfs
(*)須修正 dfs 函式
bool dfs(vector<int>& nums, int k, int average, vector<int>& out, vector<int>& visited){
    if((out.size()==(nums.size()+1)) && (k==0)) { return true; }
    for(int i=0; i<nums.size(); ++i){
        if(visited[i]==true) continue;
        if(out.back()+nums[i]>average) break;
        if(out.back()+nums[i]==average) { 
            out.push_back(0);
            --k;
        }
        else out.push_back(nums[i]+out.back());
        visited[i]=true;
        if(dfs(nums, k, average, out, visited)) return true;
        visited[i]=false;
        out.pop_back();
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
    vector<int> out(1,0);
    vector<int> visited(nums.size(),0);
    int sum=0,average=0;

    for(int i:nums){ sum+=i;}
    if(sum%k) return false;    
    average=sum/k;
    sort(nums.begin(),nums.end());    
    return dfs(nums,k,average,out,visited);        
}

//修正===
bool dfs(vector<int>& nums, int k, int start, int average, vector<int>& out, vector<int>& visited){
  if((out.size()==(nums.size()+1)) && (k==0)) { return true; }
    
  for(int i=start; i<nums.size(); ++i){
        if(visited[i]==true) continue;
        if(out.back()+nums[i]>average) break;
        if(out.back()+nums[i]==average) { 
            out.push_back(0);
            next = 0;
            --k;
        } else { 
            out.push_back(nums[i]+out.back());
            next = i+1;
        }
        visited[i]=true;
        if(dfs(nums, k, next, average, out, visited)) return true;
        visited[i]=false;
        out.pop_back();
    }
    return false;
}


#=== more challenge ===
2787. Ways to Express an Integer as Sum of Powers

#=== 思路 ===
(*) dfs + memory

1. memory 定義為 每一個sum所對應的remain值; 所以每一個level的memory為
mem[target-sum]

2. 使用 pattern為:
int dfs(,mem)
每次都回傳下一層的總counter數.

3. memory每次都記錄對應的remain值
vector<int> mem(target+1,-1) //
mem的index代表其remain值, 所以mem.size()要是target+1;
  

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

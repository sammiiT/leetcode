class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res =0;
        int n = nums.size();
        vector<int> visited(n,false);
        
        
        for(int i=0; i<n; ++i){//從index 0~n-1
            if(visited[i]) continue;
            visited[i]=true;
            
            int next;//next index
            int count;//count;
            
            next = nums[i];
            count = 1;
            
            while(true){
                if(visited[next]) break;
                visited[next] = true;    
                count = count+1;
                next = nums[next];
            }
            res = max(res,count);
        }
        return res;
    }
};
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n,false);
        if(nums.empty()) return false;
        
        
        for(int i=0; i<n; ++i){
            if(visited[i]) continue;
            visited[i] = true;
            
            unordered_map<int,int> m;//key = index, value = exist
            int cur = i;
            
            while(true){
                int next;//下一個 index
                if(nums[cur]>0){
                    next = (cur+nums[cur])%n;
                }else{//nums[cur]<0
                    next = n-1-(n-1-cur+abs(nums[cur]))%n;
                }
            
                //(1)只有一個數字
                //(2)反轉,符號相反
                if(next==cur||nums[cur]*nums[next]<0) break;
                
                if(m.count(next)) return true;//存在key
                m[cur]=next;
                cur=next;
                visited[next] = true;
            }            
        }
        return false;
    }
};
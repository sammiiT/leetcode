    bool helper1(vector<int>& nums, int k){
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(m.count(nums[i])){
                if(abs(m[nums[i]]-i)<=k) return true;
                else m[nums[i]]=i;
            }else{
                m[nums[i]]=i;
            }
        }
        return false;
    }

    bool helper0(vector<int>& nums, int k){
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(m.find(nums[i])!=m.end() && abs(m[nums[i]]-i)<=k){
                return true;
            }
            m[nums[i]]=i;
        }
        return false;
    }

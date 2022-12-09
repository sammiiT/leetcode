    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        int res;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto a:m){
            if(a.second<3){
                res = a.first;
            } 
        }
        return res;
    }

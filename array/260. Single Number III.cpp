    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;        
        }
        for(auto a:m){
            if(a.second==1)
                res.push_back(a.first);    
        }
        return res;
    }

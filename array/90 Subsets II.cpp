class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
/*
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(),nums.end());
        helper(nums,0,out,res); 
        return res;
*/        
        
        
        vector<vector<int>> res;;
        if(nums.empty()) return res;
        vector<int> out;
        
        sort(nums.begin(),nums.end());
        helper(nums,0,out,res);
        return res;
        
    }
    
    void helper(vector<int>& nums,
               int start,
               vector<int>& out,
               vector<vector<int>>& res){
        
        res.push_back(out);
        for(int i=start; i<nums.size(); ++i){
            if(i>start && nums[i]==nums[i-1]) continue;
            out.push_back(nums[i]);
            helper(nums,i+1,out,res);
            out.pop_back();
        }
        
        
    }
};


/*
    res.push_back(out);
    for(int i = start; i<nums.size(); ++i){
        // if(i>0 && (nums[i]!=nums[i-1])
            if(i>start && nums[i]==nums[i-1]) continue;
            out.push_back(nums[i]);
            subSets(nums,i+1,out,res);//i+1 表示不能重複
            out.pop_back();
        
        //當下處理的節點,等於下一個要處理的節點, 則i跳到下一個;以下描述有效
        // while((i+1<nums.size()) && (nums[i]==nums[i+1])) ++i;
    }


*/
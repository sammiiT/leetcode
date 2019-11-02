class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> res;
        if(nums.empty()) return res;
        
        int start = nums[0];
        
        for(int i=1;i<=nums.size();++i){
            if(i<nums.size() && (nums[i]==nums[i-1]+1)){
                continue;
            }else{//nums[i]!=nums[i-1]
                if(start==nums[i-1]){
                    res.push_back(to_string(start));
                }else{//start!=nums[i-1]
                    res.push_back(to_string(start)+"->"+to_string(nums[i-1]));
                }
                if(i<nums.size())start = nums[i];//重新定義start
            }
        }
        return res;
    }
    //範圍題目: 前面出現數值, 後面尚未處理;最後一組會列不出來
    //(int i=0;i<=nums.size();++i)
};
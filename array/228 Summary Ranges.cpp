//===類似題===
229. Majority Element II
163. Missing Ranges
352. Data Stream as Disjoint Intervals
//===思路===

//===
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int j = 0,i;
    string s;
    if(!nums.size()) return res;
    for(i=1; i<nums.size(); i++){
        if(nums[i-1]+1==nums[i]) continue;
            //如果只有一個數字,則只把單一一個數字加到string中
        s = (j==(i-1))?to_string(nums[j]):to_string(nums[j])+"->"+to_string(nums[i-1]);
        res.push_back(s);
        j = i;//更新開頭index
    }
    //最後一段    
    s = (j==(i-1))?to_string(nums[j]):to_string(nums[j])+"->"+to_string(nums[i-1]);
    res.push_back(s);
    return res;
}
//===思路2===
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

//===類似題===
298. Binary Tree Longest Consecutive Sequence
2177. Find Three Consecutive Integers That Sum to a Given Number
2274. Maximum Consecutive Floors Without Special Floors
129. Sum Root to Leaf Numbers
//===思路====
1.先對陣列作sort
2.對每一個element遍歷作比較

(*)參考 674. Longest Continuous Increasing Subsequence

//====
int longestConsecutive(vector<int>& nums) {
        int res = 1;//當input陣列僅有一個element,回傳1
        int count = 1;
        if(nums.size()==0) return 0;//當input為空陣列, 回傳0
        
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==(nums[i-1]+1)) {
                count++;
                res = max(count,res);
            }else if(nums[i]==nums[i-1]){
            //因為問題是sequence, 所以是set; 相等的情況不列入非consecutive elements
            }else{
                count=1;
            }
        }
        return res;
}
//===寫法2====
int longestConsecutive(vector<int>& nums) {
        int res = 0;
        int j = 0;
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());

        for(int i=1; i<nums.size(); ++i){
                if(nums[i]==(nums[i-1]+1)){
                        j++;
                }else if(nums[i]==nums[i-1]){
                        
                }else{
                        res = max(res,j);
                        j=0;
                }
        }
        res = max(res,j);
        return (res==0)?1:res+1;
        
}

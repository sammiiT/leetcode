//===類似題===
91. Decode Ways
1982. Find Array Given Subset Sums
//===思路===
(*)DFS算法
(*)先作排列sort,因為會有重複解發生
1.每次進入下一個level, 都要將當下"解"vector<int>, push到最後的result中vector<vector<int>>
2.為了防止重複解, 必須加上 if(i>start && nums[i]==nums[i-1]) continue; ==> 同一層的判斷 
Ex:[1,2,2]
1為root,  [1,2],[1,2,2],和[1,2] (第三個2), 所以要把第三個2排除;所以加上上述判斷

3.如果if(i>0 && nums[i]==nums[i-1]) 會錯誤, 會將[1,2,2]也排除

root = 1, 配對child為 [2,2] ==> 位置2(0-index)的2可以是第二層,也可以是第三層; 在第二層時, 跟位置1(0-index)的2重複
     1                     
    / \ 
   2   2(*)
  /
 2(*)   
//====
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
            if(i>start && nums[i]==nums[i-1]) continue;//同一層判斷
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

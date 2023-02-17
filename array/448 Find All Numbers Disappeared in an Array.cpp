//===類似題===
449. Serialize and Deserialize BST
1980. Find Unique Binary String
2195. Append K Integers With Minimal Sum
2295. Replace Elements in an Array
//===思路===
1.用unordered_map<int,int>記錄所有出現的數字
2.從1~n遍歷, 如果1~n中的任何一個數沒有出現在map中
3.如果沒有出現在map中, 將數值push_back至vecotr<int>中
//====
vector<int> helper0(vector<int>& nums){
    unordered_map<int,int> m;
    vector<int> res;
    for(int a:nums) m[a]++;

    for(int i=1; i<=nums.size(); i++){
        if(!m.count(i)) res.push_back(i);
    }    
    return res;
}
vector<int> findDisappearedNumbers(vector<int>& nums) {
    return helper0(nums);
}

//===思路2===
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            int idx = abs(nums[i])-1;
            if(nums[idx]>0) nums[idx] = -nums[idx];
        }
        
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }//
    
    vector<int> findDisappearedNumbers_OK(vector<int>& nums) {
         vector<int> res;
                    
         for(int i=0; i<nums.size(); ++i){
             int j = abs(nums[i])-1;
             if(nums[j]>0) nums[j]=-nums[j];
         }  
         
         for(int i=0;i<nums.size();++i){
             if(nums[i]>0) res.push_back(i+1);
         } 
         return res;
    }
};

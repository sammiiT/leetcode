//===類似題===
269. Alien Dictionary
765. Couples Holding Hands
1980. Find Unique Binary String
//===思路====
(*) index 必須等於 array[index]
(*) 如果 index!=array[index] 就是
//====
class Solution {
public:
    int missingNumber(vector<int>& nums) {
          sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();++i){
        if(nums[i]!=i) return i;
    }
    return nums.size();
  
    }
};
//========================
int helper(vector<int>& nums){
        sort(nums.begin(),nums.end());
        nums.push_back(nums[nums.size()-1]+1);//加入右邊界
        nums.insert(nums.begin(),-1);//加入左邊界
        
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i+1]!=nums[i]+1){
                return nums[i]+1;
            }    
        }
        return nums[nums.size()-1];
}

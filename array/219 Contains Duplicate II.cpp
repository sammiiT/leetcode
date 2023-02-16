//===類似題===
220. Contains Duplicate III
1989. Maximum Number of People That Can Be Caught in Tag
2441. Largest Positive Integer That Exists With Its Negative
2085. Count Common Words With One Occurrence
//===思路===
(*)unordered_map<key,val>概念
-如果直接帶入數值到map, map就會對此數值建立key;
-m[8]; 會建立 8的key, 且數值為0 ; m[8]等於0
-如果要判斷key有沒有存在,則用m.find(8)或m.count(8)
--m.find(8)是回傳iterator, 如果不存在就回傳m.end()的iterator
--m.count(8)是回傳true或false, 如果存在key,回傳true; 不存在,回傳false

1.記錄每一個key的出現位置(index)
2.如果重複出現相同的key,則判斷是不是滿足條件 abs(i-j)<=k
//====
bool helper2(vector<int>& nums, int k){
    unordered_map<int,int> m;//
    for(int i=0; i<nums.size(); i++){
        if(m.count(nums[i])){
            if(abs(m[nums[i]]-i)<=k){
                return true;
            }
        }
        m[nums[i]] = i;//udpate 新的位址
    }
    return false;
}
//=====
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums,int k){
        int n = nums.size();
        // unordered_map<int,int> m;
        unordered_map<int,int> m;
        
        for(int i=0; i<n; ++i){
            if(m.count(nums[i])){
                if(abs(m[nums[i]]-i)<=k){
                    return true;
                }else{
                    m[nums[i]]=i;//重新定義出現index
                }
            }else{
                m[nums[i]]=i;
            }
        }
        return false;
        
    }
    
    //at most k ; 最多是k
    bool containsNearbyDuplicate_fail(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n && (i+k)<n; ++i){
            
            if(nums[i]==nums[i+k]){
                return true;
            }
        }
        return false;
    }
};

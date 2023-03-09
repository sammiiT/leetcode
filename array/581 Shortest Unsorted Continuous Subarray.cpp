//===類似題===
582. Kill Process
1686. Stone Game VI
2425. Bitwise XOR of All Pairings
1090. Largest Values From Labels
//===思路===
(*)建立參考數列,此數列是重新ascending排列
-並比較這兩數列

1.從左至右,找到第一個需要排列的index
2.從右到左,找到第一個需要排列的index
3.兩個index相減 再加1,就是range

//======
int findUnsortedSubarray(vector<int>& nums) {
    int n=nums.size(),i=0,j=n-1;
    vector<int> t=nums;
        
    sort(t.begin(),t.end());
    while(i<n && t[i]==nums[i]) i++;
    while(j>i && t[j]==nums[j]) j--;
    return j-i+1;        
}

//======
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
        vector<int> res({nums.size(),0});
        
        
        for(int i=1;i<nums.size();++i){
            int tmp = nums[i];
            int j = i-1;
            
            if(nums[j]>tmp) res[1] = i;
            
            while(j>=0 && nums[j]>tmp){
                nums[j+1]=nums[j];
                --j;
            }
            nums[j+1] = tmp;
            
            if(j!=(i-1)) res[0] = min(res[0],j+1);
        }
        
        if(res[0]==nums.size() && res[1]==0) return 0;
        else return res[1]-res[0]+1;
        // return (res[0]==res[1])?0:res[1]-res[0]+1;
    }
};

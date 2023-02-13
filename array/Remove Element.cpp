//===類似題===
28. Find the Index of the First Occurrence in a String
2244. Minimum Rounds to Complete All Tasks
1213. Intersection of Three Sorted Arrays
2491. Divide Players Into Teams of Equal Skill
//===思路===
nums = [3,2,2,3], val = 3    
nums = [0,1,2,2,3,0,4,2], val = 2    
1.設定一所引 pre=-1; 初始值為-1
2. 因為要將等於val的數值刪除, 並將後面的數值往前移
3. 當遇到不等於val的數, pre+1更新, 並將不等於val的數指派給pre位置
4. 當遇到等於val的數,pre不更新; 繼續往下一個執行
5. 最後回傳pre+1 就是刪除val的總個數.    
    
//===   
class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int pre =-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val){
                pre++;
                nums[pre]=nums[i];
            }
        }
        return pre+1;
    }
    
    int removeElement_OK(vector<int>& nums, int val) {
        int cur = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==val) continue;
            
            nums[cur]=nums[i];
            cur++;
        }
        return cur;
    }
};

//===思路====
1.遍歷陣列
2.當數值等於val, 則erase; 當不等於 index+1
3.最後回傳陣列的size()

(*)考陣列的 erase() 功能, 內部要帶入的parameter   
//===
int helper0(vector<int>& nums, int val){
    int i=0;
    while(i<nums.size()){
        if(nums[i]==val){
            nums.erase(nums.begin()+i);
        }else{
            i++;
        }
    }
    return nums.size();
}

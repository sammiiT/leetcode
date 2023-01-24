//===類似題===
284. Peeking Iterator
2460. Apply Operations to an Array
//===思路===
1.遍歷數列
2.兩個index, 一個index(i)是遍歷數列用,一個index(j)是填入不等於0的index
3.當不等於0,則j遞增, 將位置i的數值填入位置j
4.最後j以後的數值全部填0
//=====
void helper0(vector<int>& nums){
    int j=-1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!=0){
            j++;
            nums[j]=nums[i];
        }
    }
    for(int i=j+1;i<nums.size();i++){
        nums[i]=0;
    }
}

//===思路2====
1.遍歷數列
2.兩個index, 一個index(i)是遍歷數列用,一個index(pre)是位在0的位置
3.如果遇到不等於0,則"等於0的位置"和"不等於0的位置"數值對換
4.遍歷完數列,即為解, 不用把最後的數值填"0"

//=======
class Solution {
public:
    //refer remove duplicate
    void moveZeroes(vector<int>& nums) {
        int pre=0;
        
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==0) continue;
            
            int tmp = nums[pre];
            nums[pre]=nums[i];
            nums[i]=tmp;
            pre++;
        }
    }
};

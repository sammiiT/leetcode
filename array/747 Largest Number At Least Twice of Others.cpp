//===類似題===
748. Shortest Completing Word
2154. Keep Multiplying Found Values by Two
//===思路1===
1.宣告兩變數,一個紀錄最大值,一個紀錄最大值的index
2.重新排列數字
3.比較最大數值(最後一個)是否為第二大數值(倒數第二個)的2倍
nums[n-1]>=2*nuums[n-2]
//====
int helper1(vector<int>& nums){
    int n = nums.size();
    int mx = 0;
    int mxid=0;
    for(int i=0; i<n; i++){
        if(mx<nums[i]) {
            mx = nums[i];
            mxid = i;
        }       
    }
    sort(nums.begin(),nums.end());
    return (nums[n-1]>=2*nums[n-2])?mxid:-1;
}
//===寫法2 同思路
int helper(vector<int>& nums){
    int index = 0;
    vector<int> res(2,0);
    res[0]=nums[0];
    for(int i=1; i<nums.size(); ++i){
        if(nums[i]>=res[0]){
            res[1]=res[0];
            res[0]=nums[i];
            index = i;
        }else if(nums[i]>=res[1]){
            res[1]=nums[i];
        }
    }
    return res[0]>=res[1]*2?index:-1;
}
//===思路2===
(*)此題跟前面有一題很像
1.宣告兩變數,一個first_max, 一個second_max; 並將兩個初始值設定為INT_MIN
2. 宣告變數index,紀錄最大值發生的位址
3.遍歷數列,找first_max和second_max,遇到first_max時,順便紀錄index
4.遍歷完數列,若second_max==INT_MIN, 表示不滿足提議回傳-1
5.若存在second_max,則判斷 (first_max>=2*second_max), 滿足回傳index

//====
int helper2(vector<int>& nums){
    int first=INT_MIN,second=INT_MIN;//
    int index;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>first){
            second = first;
            first = nums[i];
            index = i;
        }else if(nums[i]>second && nums[i]<first){
            second = nums[i];        
        }
    }
    return (second!=INT_MIN)?((first>=2*second)?index:-1):-1;
}

//====下面做同思路2====
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        long first=LONG_MIN,second = LONG_MIN;
        if(nums.size()==1) return 0;
        int id =0;
        
        for(int i=0;i<nums.size();++i){
            if(nums[i]>first){
                second = first;
                first = nums[i];
                id = i;
            }else if(nums[i]>second){
                second = nums[i];
            }
        }
        if((first-second)>=second) return id;
        else return -1;
    }
};

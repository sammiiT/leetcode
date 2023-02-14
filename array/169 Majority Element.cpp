//===類似題====
170. Two Sum III - Data structure design
1150. Check If a Number Is Majority Element in a Sorted Array
//===思路===
1.建立一map, 記錄每一個數字的出現次數
2.宣告一變數mxcnt,紀錄出現最多的次數
3.兩次遍歷, 一次紀錄每一個數字出現次數, 一次判斷出現次數最多的數字
//====
int helper1(vector<int>& nums){
    unordered_map<int,int> m;
    int mxcnt = 0;
    int ret = -1;
    for(int a: nums){
        m[a]++;
        mxcnt = max(mxcnt,m[a]);
    }
    for(auto a:m){
        if(a.second==mxcnt){
            ret= a.first;
            break;        
        }
    }
    return ret;
}
//===思路2=====
(*)賽馬算法
//========
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 1;
        
        for(int i=1; i<nums.size(); ++i){
            // if(nums[i]==nums[i-1]){
            if(majority==nums[i]){
                count+=1;
            }else{//majority!=nums[i]
                count-=1;
                if(count==0){
                    majority = nums[i];
                    count=1;
                }
            }
        }
        return majority;
    }
};

//===類似題===
415. Add Strings
923. 3Sum With Multiplicity
2354. Number of Excellent Pairs
2482. Difference Between Ones and Zeros in Row and Column
//===思路===
(*)設定三個數值,代表前三大的數值_1,_2,_3    
o , _1 , o , _2 , o , _3  

(*)遍歷數列,每一個元素跟三個數值做比較,並分為三個區間
(nums[i]>_1)
(nums[i]<_1 && nums[i]>_2)
(nums[i]<_2 && nums[i]>_3)
    
(*)發生在第一區間
nums[i] , _1 ,  _2 ,  _3
原來的數值往後推:三個數值都往後推
_3=_2, _2=_1, _1=nums[i]

(*)發生在第二區間
_1 , nums[i] , _2 ,  _3
原來後兩個數值往後推
_3=_2, _2=nums[i]

(*)發生在第三區間
_1 ,  _2 , nums[i] , _3
最後一個數值往後推
_3=nums[i]

//======
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long first = LONG_MIN;
        long second= LONG_MIN;
        long third = LONG_MIN;
        
        //不能將相同值放在同一數列,所以在判斷式中沒有"=="
        for(int i=0;i<nums.size();++i){//time complexity
            if(nums[i]>first){
                third = second;
                second = first;
                first = nums[i];
            }else if(nums[i]<first && nums[i]>second){
                third = second;
                second = nums[i];
            }else if(nums[i]<second && nums[i]>third){
                third = nums[i];
            }
        }
        
        // return (third==LONG_MIN||third==second)? first:third;
        return (third==LONG_MIN)? first:third;
    }
};

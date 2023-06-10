//===類似題===
154. Find Minimum in Rotated Sorted Array II
1665. Minimum Initial Energy to Finish Tasks
1428. Leftmost Column with at Least a One
2033. Minimum Operations to Make a Uni-Value Grid

//===思路===
(*) 利用binary_search運算可達(logn)

(*)int m = l+(r-l)/2; 求出的是first_middle, 所以l的變化必須是l=m+1.
在first_middle下,如果l的變化是l=m,則會有可能跳不出迴圈
- m = 0+(1-0)/2=0=> first_middle=0, 當target滿足在right區間, 則l=m會永遠跳不到[1]的位址
-因上述理由, l必須以(l=m+1)做更新
-因為l更新必須 (l=m+1)運算,所以在判斷的時候不可能有"等於"的條件 => if(nums[i]<target) l=m+1;
--因為(m+1)已經跳出(m)的位置;"多了1"
  
1. 判斷是否rotate array
 5,1,2,3,4
 =========================
  
 (*)沒有明確的target項作比較
 1.以 l=m+1 (遞增方向) 或 r = m (遞減方向)作為條件式的描述

沒有明確的target做比較
nums[m]<=nums[r] => 要朝遞減方向才能找到解  r=m;
- 整段m~r都是遞增, 要朝遞減方向才能找到最小值 

nums[m]>nums[r] => 要朝遞增方向移動才能找到解 l=m+1;
- 先遞減再遞增, 中間一定有包含最小值, 所以朝index 遞增方向, 才能找到最小值  

//======
int findMin(vector<int>& nums) {
    int l = 0,r = nums.size()-1;
    int res = nums[0];
    if(nums[l]>nums[r]){
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]>nums[r]) l = m+1;
            else //nums[m]<=nums[r]
                r=m;                
        }
        res = nums[r];
    }
    return res;
}

//===思路2
(*)下面的判斷式有問題, 用上面算法的判斷是比較正確
(*)下面的判斷式最後輸出沒問題,是因為題目的設計,條件會剛好滿足此運算式
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left,right;
        left = 0,right=nums.size()-1;
        if(nums[left]>nums[right]){
            while(left<right){
                int mid = left +(right-left)/2;
                if(nums[mid]<nums[right]){//右邊升序
                    right = mid;
                }else{//nums[mid]>=nums[right]===> 有"等於", 則left 不可以用mid+1, 因為會跳過l=m的解
                    left = mid+1;
                }
            }
            return nums[right];
        }
        return nums[0];
    }
}
//====類似題====
154. Find Minimum in Rotated Sorted Array II
1574. Shortest Subarray to be Removed to Make Array Sorted
1932. Merge BSTs to Create Single BST
766. Toeplitz Matrix

//====思路====
1.最小值會發生在非遞增的區間;如
[4,5,6,7,0,1,2] => 發生在(m+1)~n ;不包含m 
[5,6,7,0,1,2,4] => 發生在0~m ;包含m

2.一定發生在非遞增的區間, 所以先找非遞增區間; 所以在判斷上先執行
if(nums[m]>nums[r])//非遞增區間, l每次m+1,往右邊慢慢逼近最小值
    l = m+1;

3.走到最後,還是會到遞增區間
在遞增區間, r要往左邊逼近,最後逼近到m

//======
int helper0(vector<int>& nums){
    int l =0, r = nums.size()-1;
    if(nums[l]>nums[r]){
       while(l<r){//最後會left==right
           int m = l +(r-l)/2;
           if(nums[m]>nums[r]){//判斷區間, 右邊遞增, 但不會發生最小值
                l = m+1;//l要移動到發生極值的地方       
           }else{//nums[m]<=nums[r]//判斷區間, 左邊遞增,極小值發生在 (左半邊+m)
               r = m;//r要移到發生極值的地方
           }
       }
       return nums[r];
    }
    return nums[0];
}

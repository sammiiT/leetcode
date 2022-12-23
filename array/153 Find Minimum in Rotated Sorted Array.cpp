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
                }else{//nums[mid]>=nums[mid]
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



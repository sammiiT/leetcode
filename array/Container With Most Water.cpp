class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
   int right=n-1;
   int left = 0;
   int res = 0;

   while(left<right){
       if(height[left]>height[right]){
           res = max(res,height[right]*(right-left));
           right--;
       }else if(height[left]<height[right]){
           res = max(res,height[left]*(right-left));
           left++;
       }else{
          res = max(res,height[left]*(right-left));
           left++;
       }
   }
   return res;
  
    }
};
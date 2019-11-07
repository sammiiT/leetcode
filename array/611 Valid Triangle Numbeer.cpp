class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
	    sort(nums.begin(),nums.end());

        for(int i=0; i<n; ++i){
            for(int j = i+1; j<n; ++j){
            int sum = nums[i]+nums[j];
            int left=j+1, right=n;
            while(left<right){
                int mid = left + (right-left)/2;
                if(nums[mid]<sum){//sum:兩邊和
                    left = mid +1;//要計算到nums[mid]是>= sum的情況; 
                }else{//nums[mid]>=sum//邊界, 兩邊和 小於等於第三邊nums[i]
                right = mid;
                }
            }//left = right;
            res = res+right-(j+1);    
            }
        }
        return res;        
    }
};
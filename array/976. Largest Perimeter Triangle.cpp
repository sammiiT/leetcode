//===類似題===
977. Squares of a Sorted Array
812. Largest Triangle Area
//===思路===
(*)三角形滿足公式:兩小邊和>最大邊
1.將陣列作排列, 從大到小
2.遍歷陣列, 每次比較nums[i] < nums[i+1]+nums[i+2]
-i是最大邊, (i+1)和(i+2)是兩小邊

(*)兩邊和大於第三邊
    兩邊差小於第三邊
    
//=====
int largestPerimeter(vector<int>& nums){
    int res = 0;
    sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
    for(int i=0; i<nums.size()-2; i++){
        if(nums[i]<(nums[i+1]+nums[i+2])){
            res = max(res,nums[i]+nums[i+1]+nums[i+2]);
        }
    }
    return res;
}

//===寫法2===
int largestPerimeter(vector<int>& nums) {
    int res = 0;
    sort(nums.begin(),nums.end());

    for(int i=nums.size()-1; i>=2; --i){//[0,1,2]
        if((nums[i-2]+nums[i-1])>nums[i] && (nums[i]-nums[i-1])<nums[i-2]){
            res = max(res,nums[i]+nums[i-1]+nums[i-2]);
        }
    }
    return res;
}

//===類似題===
397. Integer Replacement
1453. Maximum Number of Darts Inside of a Circular Dartboard
2088. Count Fertile Pyramids in a Land
467. Unique Substrings in Wraparound String


//===思路===
1. 規律公式 
f(n) = f(n-1) + sum -n*arr[n-1];
n是array size

//===
 int helper0(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        int a = 0;
        int res =0;
        
        for(int i=0;i<n;i++) {
            a+=i*nums[i];//f0;找出f0       
            sum+=nums[i]; //找出sum
        }
        res = a;//f0,要從f1開始
        for(int i=1; i<n; i++){//從f1開始,跟f0比
            a = a +sum-n*nums[n-i];//規律公式;計算f(n)
            res = max(res, a);//比較取出極大值        
        }
        return res;
}

int maxRotateFunction(vector<int>& nums) {
        return helper0(nums);
}

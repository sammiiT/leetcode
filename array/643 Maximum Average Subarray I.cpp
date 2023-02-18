//===類似題===
644. Maximum Average Subarray II
644. Maximum Average Subarray II
2090. K Radius Subarray Averages
//===思路===
1. sum 陣列, 每一個元素紀錄了index_0~index_i的總和
2. 如果計算 i~j的總和; 則sum[j]-sum[i-1]
//====
double helper1(vector<int>& nums, int k){
        vector<int> sum=nums;
        double mx = INT_MIN;
        for(int i=1; i<nums.size(); i++){
            sum[i]=sum[i-1] + nums[i];
        }
        for(int i=k; i<nums.size(); i++){
            mx=max((double)(sum[i]-sum[i-k])/k,mx);
        }
        mx = max((double)sum[k-1]/k, mx);
        return mx;
}

double helper2(vector<int>& nums, int k){
        vector<int> sum = nums;
        double mx;

        for(int i=1; i<nums.size(); i++){
            sum[i]=sum[i-1]+nums[i];
        }
        mx = sum[k-1];
        for(int i=k; i<nums.size(); i++){
            mx = max((double)(sum[i]-sum[i-k]),mx);
        }
        return mx/k;
}

double helper0(vector<int>& nums, int k){//time limit exceeded
        double mx = INT_MIN;
        int n = nums.size();
        for(int i=k; i<=n; i++){//log(n^2)
            double sum = 0;
            for(int j=i-k; j<i; j++) { sum+=nums[j]; }
            mx = max(sum/k,mx);        
        }
        return mx;
}
//=====
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums= nums;
        
        for(int i=1; i<n; ++i){
            sums[i] = sums[i-1] + nums[i];
        }
        
        double mx = sums[k-1];

        for(int i=k; i<n; ++i){
            mx = max(mx, (double)(sums[i]-sums[i-k]));
        }
        return mx/k;
    }
};

/*
[5] 1


*/




/*
 0, 1, 2, 3, 4,5
[1,12,-5,-6,50,3]
    j = i+1 = 1+1 =2
    (j<i+k) => (j<1+4) => (j<5) => (j =2 ~ 4)

*/

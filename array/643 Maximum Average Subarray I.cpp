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
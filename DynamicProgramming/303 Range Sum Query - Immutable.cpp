class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum = sum+nums[i];
            ary.push_back(sum);//計算累加數列
        }
    }
    
    int sumRange(int i, int j) {
        if(ary.empty()) return 0;
        return (i==0)?ary[j]:(ary[j]-ary[i-1]);
    }
    
private:
    vector<int> ary;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
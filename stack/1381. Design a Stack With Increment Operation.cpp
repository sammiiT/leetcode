//===類似題===
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
1950. Maximum of Minimum Values in All Subarrays
2028. Find Missing Observations
2576. Find the Maximum Number of Marked Indices
//===思路====
(*)題意: 如果k小於stack的數目, 
-則stack中k個element都加上val

如果k大於stack的數目
-則stack中所有的element加上val

(*)用vector<int>來實作stack
- nums.push_back(x) => stk.push()
- nums.pop_back()   => stk.pop()
- nums.back()       => stk.top()
  
//====
class CustomStack {
public:
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(nums.size()<mx)
            nums.push_back(x);    
    }
    
    int pop() {
        if(nums.size()) {
            int p = nums.back();
            nums.pop_back();
            return p;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int n = nums.size();
        int i=0;
        if(k<=n){
            for(i=0; i<k; i++){
                nums[i]+=val;
            }        
            return;
        }
        for(;i<n;i++){ nums[i]+=val; }
    }
private:
    int mx;
    vector<int> nums;
};

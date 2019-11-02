class Solution {
public:
    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> tmp = nums;
        k=k%n;
        for(int i=0; i<n; ++i){
            nums[(i+k)%n] = tmp[i];
        }
    }
    
    void rotate_OK(vector<int>& nums, int k) {
       
        vector<int> tmp = nums;
        
        for(int i=0;i<nums.size();++i){
            nums[(i+k)%nums.size()] = tmp[i];
        }
    }
};
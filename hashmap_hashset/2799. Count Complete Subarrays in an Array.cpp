//===類似題===
2800. Shortest String That Contains Three Strings
992. Subarrays with K Different Integers
//===思路===

//====
int countCompleteSubarrays(vector<int>& nums) {
    set<int> st(nums.begin(),nums.end());
    int n = st.size();
    int m = nums.size();
    int res = 0;

    for(int i=0; i<m; ++i){
        set<int> s;
        for(int j=i; j<m; ++j){
            s.insert(nums[j]);
            if(s.size()==st.size()) res+=1;
            else if(s.size()>st.size()) break; 
        }
    }
    return res;
}

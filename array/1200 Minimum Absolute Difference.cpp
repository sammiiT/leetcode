class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        int tmp = INT_MAX;
        sort(arr.begin(),arr.end());
        
        for(int i =1; i<n; ++i){
            int diff = abs(arr[i]-arr[i-1]);
            tmp = min(tmp,diff);
        }
        
        for(int i=1; i<n; ++i){
            if(abs(arr[i]-arr[i-1])==tmp){
                res.push_back({arr[i-1],arr[i]});
            }
        }
        
        // for(int i=1; i<n; ++i){
        //     if(abs(arr[i]-arr[i-1])==tmp){
        //         vector<int> v(2,0);
        //         v[0]= arr[i-1];
        //         v[1]= arr[i];
        //         res.push_back(v);
        //     }
        // }
        return res;
    }
};
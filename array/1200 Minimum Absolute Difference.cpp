//===類似題===
1201. Ugly Number III
2144. Minimum Cost of Buying Candies With Discount
//===思路===
(*)先sort陣列
1.遍歷數列, 第一次計算minimum
2.遍歷數列,第二次紀錄滿足minimum的兩元素
//====
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    int mi = INT_MAX;
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++){
        mi = min(mi,(arr[i+1]-arr[i]));
    }

    for(int i=0;i<arr.size()-1;i++){
        if(mi == (arr[i+1]-arr[i]))
            res.push_back({arr[i],arr[i+1]});
    }
    return res;
}

//===
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

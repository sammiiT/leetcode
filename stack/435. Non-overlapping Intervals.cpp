//===類似題===
436. Find Right Interval
452. Minimum Number of Arrows to Burst Balloons
2446. Determine if Two Events Have Conflict
//===思路===


//========
int helper0(vector<vector<int>>& intervals) {
    stack<vector<int>> stk;
    sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){return a[1]<b[1];});
    for(vector<int> a:intervals){
        if(stk.empty()) stk.push(a);
        else{
            vector<int> t = stk.top();
            if(t[1]<=a[0]) stk.push(a);
        }
    }
    return intervals.size()-stk.size();
}

//===思路2===
int helper1(vector<vector<int>>& intervals) {
    int res = 0, n = intervals.size(), last = 0;
    sort(intervals.begin(),intervals.end());
    for(int i = 1; i<n; i++){
        if(intervals[i][0]<intervals[last][1]){
            ++res;
            if(intervals[i][1]<intervals[last][1]) last = i;
        }else{
            last = i;
        }
    }
    return res;
}

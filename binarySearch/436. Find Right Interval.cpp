//===類似題===
1. Two Sum
352. Data Stream as Disjoint Intervals

//===思路===

//===
int lower_bound(vector<vector<int>>& mat,int target){
        int l=0, r=mat.size();
        int m;
        while(l<r){
            m=l+(r-l)/2;
            if(mat[m][0]<target) l=m+1;
            else r=m;
        }
        return r;//index
}

vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        vector<vector<int>> tmp = intervals;
        unordered_map<int,int> mp;

        sort(tmp.begin(),tmp.end(), [](vector<int>& a,vector<int>& b){ return a[0]<b[0];});

        for(int i=0;i<intervals.size();++i) {mp[intervals[i][0]]=i;}

        for(int i=0;i<intervals.size();++i){
            int index = lower_bound(tmp,intervals[i][1]);
            if(index>=intervals.size()) {res.push_back(-1);}
            else{
                res.push_back(mp[tmp[index][0]]);
            }
        }
        return res;
}

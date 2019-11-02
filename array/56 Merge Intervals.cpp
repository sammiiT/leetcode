class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        if(intervals.empty()||intervals.size()==1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end()
             ,[](vector<int>& a,vector<int>& b){return (a[0]<b[0]);});       
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); ++i){
            vector<int> tmp = res.back();
            
            if(tmp[1]>=intervals[i][0]){
                tmp[1]=max(tmp[1],intervals[i][1]);
                res[res.size()-1] = tmp;
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
        
    }
    
    
    vector<vector<int>> merge_fail(vector<vector<int>>& intervals) {
       if(intervals.empty()||intervals.size()==1) return intervals;
        
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); ++i){
            vector<int> tmp = res.back();
            
            if(tmp[1]<intervals[i][0] && tmp[0]<intervals[i][0]){
                res.push_back(intervals[i]);
                continue;
            }
            
            if(tmp[1]>=intervals[i][0]){
                tmp[1]=max(tmp[1],intervals[i][1]);
            }
            
            if(tmp[0]>=intervals[i][0]){
                tmp[0]=intervals[i][0];
            }
            res[res.size()-1]=tmp;
        }
        return res;
    }
};


/*
[[1,4],[0,4]]


*/
//===類似題===
58. Length of Last Word
715. Range Module
2276. Count Integers in Intervals

//====思路===

//=====
    vector<vector<int>> helper0(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){return a[0]<b[0];});

        res.push_back(intervals[0]);
        for(int i=1,j=0; i<intervals.size(); i++){
            if(res[j][1]>=intervals[i][0]){
                res[j][0]=min(res[j][0],intervals[i][0]);
                res[j][1]=max(res[j][1],intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return helper0(intervals, newInterval);
    }

//===思路===
    vector<vector<int>> helper1(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        if(intervals.size()==0) {
            res.push_back(newInterval);
            return res;
        }
        
        for(int i=0; i<intervals.size()+1; i++){//比較快
            if(i==intervals.size()) {
                intervals.push_back(newInterval);
                break;
            }
            if(intervals[i][0]>=newInterval[0]){
                intervals.insert(intervals.begin()+i,newInterval);        
                break;
            }
        }

        res.push_back(intervals[0]);
        for(int i=1,j=0; i<intervals.size(); i++){
            if(res[j][1]>=intervals[i][0]){
                res[j][0]=min(res[j][0],intervals[i][0]);
                res[j][1]=max(res[j][1],intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
    }

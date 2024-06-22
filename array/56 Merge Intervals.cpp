//==== 類似題 ====
57. Insert Interval
252. Meeting Rooms
253. Meeting Rooms II
495. Teemo Attacking
//====思路====
0. 先sort一次
2.新建且定義解 vector<vector<int>> res 
3.初始值, 指派給res; res.push_back(intervals[0])
4. res的最後一個元素, 都跟intervals去做比較
5.for遍歷陣列, 比較 res[res.size()-1][1] 和 intervals[i][0] 是否overlay
5.1 做合併

//=======
vector<vector<int>> helper2(vector<vector<int>>& intervals){
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){ return a[0]<b[0];});     
    res.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(res.back().back()>=intervals[i][0]) res.back().back()=max(res.back().back(),intervals[i][1]);
        else res.push_back(intervals[i]);
    }
    return res;
}

vector<vector<int>> helper1(vector<vector<int>>& intervals){
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){ return a[0]<b[0];});     
    res.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(res[res.size()-1][1]>=intervals[i][0]) res[res.size()-1][1]=max(res[res.size()-1][1],intervals[i][1]);
        else res.push_back(intervals[i]);
    }
    return res;
}

//===寫法2===
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;

    sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    });  
    res.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); ++i){

        if(res.back()[1]<intervals[i][0]) res.push_back(intervals[i]);//如果([i-1][1]<[i][0]); 區間沒有重和
        else if(res.back()[1]<=intervals[i][1]){//區間有重和, 比較[i-1][1],[i][1]哪一個比較大
            res.back()[1] = intervals[i][1];    
        }
    }
    return res;
}

//====
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
//====================================================
static bool compare(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
}
vector<vector<int>> helper(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> res;
    
    sort(intervals.begin(),intervals.end(),compare);
    res.push_back(intervals[0]);

    for(int i=1;i<n;i++){
/*        if(res[i-1][1]>=intervals[i][0]){//合併後, 下一次的res是陣列的最後一個元素
            res[i-1][1] = intervals[i][1];//所以用i索引的方式錯誤
        }*/
        if(res[res.size()-1][1]>=intervals[i][0]){//合併後, 下一次的res是陣列的最後一個元素
                //res[res.size()-1][1] = intervals[i][1];//所以用i索引的方式錯誤
                res[res.size()-1][1] = max(res[res.size()-1][1],intervals[i][1]);
        }
        else {
            res.push_back(intervals[i]);
        }   
    }
    return res;
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return helper(intervals);
}


/*
[[1,4],[0,4]]


*/

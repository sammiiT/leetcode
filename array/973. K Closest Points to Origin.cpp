//=====類似題===
974. Subarray Sums Divisible by K
692. Top K Frequent Words
1779. Find Nearest Point That Has the Same X or Y Coordinate

//===思路====

//=====
vector<vector<int>> helper0(vector<vector<int>>& points, int k){
    vector<vector<int>> res;
    sort(points.begin(),points.end(),
        [](vector<int>& a,vector<int>& b){return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];});

    for(int i=0;i<k;i++){
            res.push_back(points[i]);
    }
    return res;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return helper0(points,k);
}
//====
struct cmp{
  bool operator()(vector<int>& x ,vector<int>& y){
      return x[0]*x[0]+x[1]*x[1] > y[0]*y[0]+y[1]*y[1];
  }  
};

vector<vector<int>> helper1(vector<vector<int>>& points, int k){
    vector<vector<int>> res;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    for(int i=0;i<points.size();i++){
        pq.push(points[i]);
    }
    while(!pq.empty()&&res.size()<k){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

int kthSmallest(vector<vector<int>>& matrix, int k){
     int l = matrix[0][0],r = matrix.back().back();
     while(l<r){
        int m = l+(r-l)/2;
        int cnt = 0;
        for(int i=0; i<matrix.size(); i++){
            //每一列的 upper_bound全部加起來, 就是所有的upper_bound=> supper position概念
            cnt = cnt + upper_bound(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin();
        }
        if(cnt<k) l=m+1; // k是 target       
        else// cnt>=k
            r = m;
    }
    return r;
}



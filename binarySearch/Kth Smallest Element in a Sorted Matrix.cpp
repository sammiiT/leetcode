int kthSmallest(vector<vector<int>>& matrix, int k){
     int l = matrix[0][0],r = matrix.back().back();
     while(l<r){
        int m = l+(r-l)/2;
        int cnt = 0;
        for(int i=0; i<matrix.size(); i++){
            cnt = cnt + upper_bound(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin();
        }
        if(cnt<k) l=m+1;       
        else// cnt>=k
            r = m;
    }
    return r;
}



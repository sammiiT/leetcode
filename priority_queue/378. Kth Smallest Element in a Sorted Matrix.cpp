//===類似題===
379. Design Phone Directory
668. Kth Smallest Number in Multiplication Table
719. Find K-th Smallest Pair Distance
786. K-th Smallest Prime Fraction

//===思路1===
(*)用priority_queue
1.遍歷matrix陣列, 將每一個元素push到q中
1.1 push到q中的元素,會以最大值放在top
2.當q.size()超過 k, 就把top()剔除
3.遍歷完之後, 回傳top(),即解
//======
int helper1(vector<vector<int>>& matrix, int k){
    priority_queue<int> pq;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            pq.push(matrix[i][j]);
            if(pq.size()>k) pq.pop();
        }
    }
    return pq.top();

}
//===思路2===
(*) binary search搭配upper bount
//======
int helper0(vector<vector<int>>& matrix, int k){
    int l = matrix[0][0], r = matrix.back().back();//在數列中
    while(l<r){//r = the final element => 確認"解"一定在數列中, 所以l==r狀態不用討論
        int cnt = 0;
        int m = l+(r-l)/2;
        for(int i=0; i<matrix.size(); i++)
/*
不能用lower_bound, 因為是用數值做判斷, 不是用index來判斷
(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin();  => m是數值
且回傳值 (r = m) m 有可能不在數列中
所以用upper_bound,一定確保cnt落在陣列的某個index內, 且index對應的數值存在; 用lower_bound則 index對應的數值不見得存在於陣列
*/        
            //cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin();
            cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin();
        if(cnt<k) l = m+1; ////經middle運算後的值小於target, middle所對應的值小於target
        else//cnt>=k 
            r = m;//middle對應的值大於等於target
    }             //最後解會發生在此區間
    return r;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        return helper1(matrix,k);
    }

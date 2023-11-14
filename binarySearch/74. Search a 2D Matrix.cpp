//====類似題====
75. Sort Colors
2468. Split Message Based on Limit

//===思路====
1.先找到target落在哪一個區間, 每一個區間就是每一列的所有數值
2.找到特定的列之後, 用binary search做判斷
  
//=====
int helper(vector<int>& nums, int target,int l, int r){
    while(l<=r){
        int m = l+(r-l)/2;
        if(nums[m]<target){
            l = m+1;
        }else if(nums[m]>target){
            r = m-1;
        }else{//nums[m]==target
            return m;
        }
    }
    return -1;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int ret=false;
    for(int i=0; i<matrix.size(); i++){
      if(target > matrix[i][matrix[i].size()-1]){ continue; }//搜尋target落的區間,以每一列的最大值做比較
      else {// if(target<=matrix[i][matrix[i].size()-1])
            int l = 0;
            int r = matrix[i].size()-1;
            if(helper(matrix[i],target, l, r)==-1){ return false; }//區間內做binary search
            else{ return true; }
        }
    }
    return false;
}

//====思路====
(*)

//====
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if(matrix.empty()) return false;
  int r = matrix.size(), i = r;
  int c = matrix[0].size(), j = c-1;
  
  while(i<r && j>=0){
    if(target>matrix[i][j]){ i++;}
    else if(target<matrix[i][j]){ j--; 
    else{//target == matrix[i][j]
      return true;
    }
    return false;
  }  
}

//====思路====
1.先求解落在哪一個row
2.再求解落在哪一個column 
3.用binary search
  
//====  
bool helper1(vector<vector<int>>& matrix, int target){
  int left = 0,right = matrix.size();
  while(left<right){//
    int m = left + (right-left)/2;
    if(matrix[m][0]<target) left = m+1;
    else if(matrix[m][0]>target) right =m;
    else //matrix[m][0]==target ,將"="獨立出來, 最後的解,為upper_bound
        return true;
  }//upper_bound
  int tmp = (right>0)? right-1: right;//row, 因為是upper_bound,所以要right-1
  
  left = 0; right = matrix[tmp].size();
  while(left<right){
    int m = left+(right-left)/2;
    //if(matrix[tmp][m]==target) return true;
    if(matrix[tmp][m]<target) left = m+1;
    else if(matrix[tmp][m]>target) right = m;
    else return true;
  }
  return false;
}  
//===思路===
  (*)row和column方向皆用binary+search
  1.先對row方向做binary_search
  2.找到target所在的row之後, 再對column方向做binary_search
  
  bool searchMatrix(vector<vector<int>>& mat, int target){
    int row;
    int l = 0, r = mat.size()-1;//先對row方向做搜尋
    while(l<r){
        int m = l+(r-l)/2;
        if(mat[m][0]<target) l = m+1;
        else//mat[m][0]>=target
            r = m;
    }
    
    if(mat[r][0]==target) return true;//剛好等於target
    
    if(mat[r][0]>target){ row = r-1; //如果找到的是upper_bound, 則發生target的地方在r-1 row
    }else if(mat[r][0]<target){ row = r; }//如果找到的位址小於target, 則在原r搜尋
    if(row<0) return false;//如果 r-1<0 ; 例如 [[1]], target==0; 會發生r-1<0狀況

    l=0, r=mat[row].size();
    while(l<r){//再用binary_search找一次
        int m = l+(r-l)/2;
        if(mat[row][m]<target) l=m+1;
        else//
            r = m;
    }
    return r>=mat[row].size()?false:(mat[row][r]==target)?true:false;
}

//===寫法 2=====
(*)用lower_bound()概念
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for(int i=0; i<m; ++i){
        int idx = lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
        if(idx==n) continue;
        if(matrix[i][idx]==target) return true;
    }
    return false;
}    
  
  
  
  

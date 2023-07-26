//===類似題===
75. Sort Colors
2468. Split Message Based on Limit
//===思路===
(*)用binary search
1.先搜尋落在哪一個row=> binary_search uppder_bounded
2.找到對應的row, 再用binary_search搜尋column中的的數值
//====
bool helper2(vector<vector<int>>& matrix, int target){
    int l=0, r = matrix.size();
    while(l<r){
        int m = l+(r-l)/2;
        if(matrix[m][0]==target) return true;
        else if(matrix[m][0]<target) l = m+1;
        else if(matrix[m][0]>target) r = m;
    }//upper_bound

    int tmp = r>0?r-1:r;//落在如果小於第一個數值則upper_bounded為0
    l = 0;r = matrix[0].size()-1;
    while(l<=r){//binary_search
        int m = l+(r-l)/2;
        if(matrix[tmp][m]==target) return true;
        else if(matrix[tmp][m]<target) l = m+1;
        else if(matrix[tmp][m]>target) r = m-1;
    }
    return false;
}

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
            if(target > matrix[i][matrix[i].size()-1]){
                continue;
            }
            else {// if(target<=matrix[i][matrix[i].size()-1])
                int l = 0;
                int r = matrix[i].size()-1;
                if(helper(matrix[i],target, l, r)==-1){
                    return false;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
//===思路2====
1.從rowMax-1, colum=0開始
2.如果小於,則往前一個row移動
2.如果大於,則往colum遞增方向移動
//====
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int r = matrix.size();
        int c = matrix[0].size();
        int i=0;
        int j = c-1;
        while(i<r && j>=0)    
        if(target > matrix[i][j]){
            i++;
        }else if(target < matrix[i][j]){
            j--;
        }else{//target==matrix[i][j]
            return true;
        }
        return false;
    }
//===思路3====
(*)用lower_bound或upper_bound求解
不考慮超過size()的index值, 所以只討論(idx<n)的範圍內

-lower_bound
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i=0;i<m;++i){
        int idx = lower_bound(matrix[i].begin(),matrix.end(),target)-matrix[i].begin();
        if(idx<n && matrix[i][idx]==target) return true;
    }
    return false;
}    

- upper_bound
如果不在upper_bound範圍, idx==0,所以有解的結果會發生在
(idx>0)的情況
    
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0; i<m; ++i){
        int idx = upper_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
        if(idx>0 && matrix[i][idx-1]==target) return true;
    }
    return false;
}    





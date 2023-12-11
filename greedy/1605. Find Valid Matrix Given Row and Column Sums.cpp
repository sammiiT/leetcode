//===類似題===
1570. Dot Product of Two Sparse Vectors
1253. Reconstruct a 2-Row Binary Matrix

//===思路====
(*) Greedy
- 但此題是要取兩數中最小的那一個 min

1.建立vector<vector<int>>二維陣列
2.遍歷rowSum和colSum
-取rowSum[i]或colSum[j]最小的那一個

rowSum = [5,7,10], colSum = [8,6,8]

    /--grid[0][0],                             /--決定grid[0][0]=5
   /  比較rowSum[0]和colSum[0],取min=5;        /  rowSum[0]-=min; colSum[0]-=min
  O   O   O  5                                5   O   O   0                            
  O   O   O  7                                O   O   O   7
  O   O   O  10                               O   O   O   10 
  8   6   8                                   3   6   8
    
    
        /--grid[0][1]                              /--grid[0][1]=0
       / 比較rowSum[0]和colSum[1],取min=0          / rowSum[0]-=min; colSum[0]-=min
  5   O   O  0                                5   0   O  0
  O   O   O  7                                O   O   O  7
  O   O   O  10                               O   O   O  10 
  3   6   8                                   3   6   8
    
=> 5 0 0   
   3 4 0 
   0 2 8  
 
    
//=====
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size(), n = colSum.size();
    vector<vector<int>> res(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int a = min(rowSum[i],colSum[j]);        
            res[i][j] = a;
            rowSum[i]-=a;
            colSum[j]-=a;
        }
    }
    return res;
}

//===思路2===
(*)遍歷2d陣列;遍歷順序:由左至右,由上而下
-比較[i],[j]大小
--如果[j]比較大,取[i],先對[j]做-[i]運算,再對[i]做[i]-=[i]運算
--如果[i]比較大,取[j],先對[i]做-[j]運算,再對[j]做[j]-=[j]運算

    8            6        8
5  取5(剩0)     取0       取0  
   (剩3)        (剩6)    (剩8) 
7  取3(剩4)     取4(剩0)  取0
   (剩0)        (剩2)    (剩8)
10  取0(剩10)    取2(剩8)  取8  

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    vector<vector<int>> res(rowSum.size(),vector<int>(colSum.size(),0));

    for(int i=0; i<rowSum.size(); ++i){//x
        int x = rowSum[i];    
        
        for(int j=0; j<colSum.size(); ++j){//y
            
            if(x<colSum[j]){
                res[i][j]=x;
                colSum[j]-=x;
                x-=x;
                //colSum[j]-=x;//放在這邊會錯誤;要先對colsum執行相減運算
            
            }else{//x>=colSum[j]
                res[i][j]=colSum[j];
                x-=colSum[j];
                colSum[j]-=colSum[j];
                //x-=colSum[j];
            }        
        }
    }
    return res;
}

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
  int m = rowSum.size(), n = colSum.size();
  vector<vector<int>> res(m,vector<int>(n));
  int i=0;j=0;
//while(i<m || j<n){
  while(i<m && j<n){
      res[i][j]=min(rowSum[i],colSum[j]);
      if(rowSum[i]<colSum[j]){
          colSum[j]-=rowSum[i];
          i+=1;
      }else if(rowSum[i]>colSum[j]){
          rowSum[i]-=colSum[j];
          j+=1;
      }else{//rowSum[i]==colSum[j]
          i+=1;
          j+=1;
      }
  }
  return res;
}

//===寫法2====
同上述greedy概念

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> res(m,vector<int>(n,0));
    
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(rowSum[i]<colSum[j]){
                res[i][j]=rowSum[i];
                colSum[j]-=rowSum[i];//要先算colum
                rowSum[i]-=rowSum[i];
                //colSum[j]-=rowSum[i];
            }else{//rowSum[i]>=colSum
                res[i][j] = colSum[j];
                rowSum[i]-=colSum[j];//要先算row
                colSum[j]-=colSum[j];
            }
        }
    }
    return res;        
}





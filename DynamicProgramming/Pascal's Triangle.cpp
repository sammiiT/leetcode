    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows,vector<int>());
        
        for(int i=0; i<numRows; i++){//層數=執行次數
            res[i].resize(i+1,1);//設定一層, 初始值為1
            for(int j=1; j<i; j++){//設定每一層的element
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }

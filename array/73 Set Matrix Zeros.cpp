//===類似題===
645. Set Mismatch
289. Game of Life
2125. Number of Laser Beams in a Bank
2123. Minimum Operations to Remove Adjacent Ones in Matrix

//===思路===
1.紀錄x 方向映射
2.紀錄y 方向映射
3.遍歷所有位址, 如果遇到x[i]或y[j]為0的, 就將matrix[i][j]設為0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        
        //(1)找出第一個點
        //(2)將其他點映射到第一個點的十字座標上
        //(3)十字座標以外的區域,對應之前的映射點, 設定為0(row, column設定為0)
        //(4)將十字座標row, column上的點都設定為0
        
        int zero_i=-1,zero_j=-1;
        int has_zero = 0;
        if(matrix.empty()){return;}
        
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0;j<matrix.front().size();++j){
                if(matrix[i][j]==0){
                    if(!has_zero){
                        zero_i=i;
                        zero_j=j;
                        has_zero=1;
                    }
                    matrix[zero_i][j]=0;
                    matrix[i][zero_j]=0;
                }
            }
        }
        
        if(has_zero){
        
            for(int i=0;i<matrix.size();++i){
                if(i==zero_i) continue;
                for(int j=0;j<matrix.front().size();++j){
                    if(j==zero_j) continue;
                    if(matrix[i][zero_j]==0 || matrix[zero_i][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }

            for(int i = 0;i<matrix.size();++i){//固定j = zero_j
                matrix[i][zero_j]=0;
            }
            for(int j=0;j<matrix.front().size();++j){//固定i = zero_i
                matrix[zero_i][j]=0;
            }
        }
        
        
    }
};

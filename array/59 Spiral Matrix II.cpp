//===類似題===
60. Permutation Sequence
885. Spiral Matrix III
2326. Spiral Matrix IV

//===思路===
(*)54.Spiral Matrix 方法 ,修正
1.建立一nxn matrix
2.執行Sprial, 並根據路徑計算(i,j)
3.將對應的數值帶入 matrix[i][j]=val;
//====
void helper1(int k, vector<vector<int>>& res){
    int m = k, n = k;
    int cnt = 0;
    int rmin=0,rmax=m-1;
    int cmin=0,cmax=n-1;
    enum{LEFT,RIGHT,UP,DOWN};
    int action = RIGHT;
    int i = 0, j = 0;
    int num = 1;

    while(cnt<m*n){//2.執行Sprial, 並根據路徑計算(i,j)
        res[i][j]=num++;//3.將對應的數值帶入 matrix[i][j]=val;
        if(++cnt<m*n){
            switch(action){
                case(RIGHT):
                    if(j+1<=cmax){ j++;
                    }else{
                        i++;
                        rmin++;
                        action = DOWN;
                    }               
                break;
                case(LEFT):
                    if(j-1>=cmin){ j--;
                    }else{
                        i--;
                        rmax--;
                        action = UP;
                    }
                break;
                case(UP):
                    if(i-1>=rmin){ i--;
                    }else{
                        j++;
                        cmin++;
                        action = RIGHT;
                    }
                break;
                case(DOWN):
                    if(i+1<=rmax){ i++;
                    }else{
                        j--;
                        cmax--;
                        action = LEFT;
                    }
                break;
            }
        }
    }
}

//====
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //vector<int>(n): 初始值為0
        vector<vector<int>> matrix(n,vector<int>(n));
        enum Action{RIGHT,DOWN,LEFT,UP};
        Action action = RIGHT;
        for(int i=0,j=0,cnt=0,total=n*n;cnt<total;){
            matrix[i][j]=++cnt;
            switch(action){
                case(RIGHT):
                    if(j+1<n && matrix[i][j+1]==0){
//matrix[i][j+1]下一個是0的話,表示沒有值填入; 同時也是轉折條件
//繞到第二圈的時候,外圈已經有填入數值了,當填入數值就不是0
                        ++j;
                    }else{
                        ++i;
                        action=DOWN;
                    }
                    break;
                case(DOWN):
                    if(i+1<n && matrix[i+1][j]==0){
                        ++i;
                    }else{
                        --j;
                        action=LEFT;
                    }
                    break;    
                case(LEFT):
                    if(j-1>=0 && matrix[i][j-1]==0){
                        --j;
                    }else{
                        --i;
                        action=UP;
                    }
                    break;   
                case(UP):
                    if(i-1>=0 && matrix[i-1][j]==0){
                        --i;
                    }else{
                        ++j;
                        action=RIGHT;
                    }
                    break;
                default:
                    break;
            }
        }
        return matrix;
    }
};

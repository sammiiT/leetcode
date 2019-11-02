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
//===類似題===
55. Jump Game
885. Spiral Matrix III
2326. Spiral Matrix IV
//===思路===
(*)先賦值,再移動
(*)邊界要定義
//===
class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    int r = matrix.size();
    vector<int> res;
    if(r==0) return res;
    int c = matrix[0].size();
    enum Action{RIGHT,LEFT,UP,DOWN};
    Action action = RIGHT;
    
    
    int total = r*c;
    //先賦值,再移動==> 因為一開始在陣列的起始點上,   如果開始不在陣列起始點, 就要先移動, 再賦值
    for(int i=0,j=0,begini=0,beginj=0,endi=r,endj=c,cnt=0; cnt<total; ++cnt){
        res.push_back(matrix[i][j]);//先賦值
  
        switch(action){//再移動
                    case(RIGHT):
                    if(j+1<endj){//小於endj是因為 endj初始值是c(是count base), 不是index base
                        ++j;
                    }else{
                        action = DOWN;
                        ++i;
                        ++begini;
                    }
                    break;
                    
                case(DOWN):
                    if(i+1<endi){//小於endj是因為 endi初始值是r(是count base), 不是index base
                        ++i;
                    }else{
                        action = LEFT;
                        --j;
                        --endj;
                    }
                    break;
                
                case(LEFT):
                    if(j-1>=beginj){//>=;有等於是因為beginj是從0開始, index base
                        --j;
                    }else{
                        action = UP;
                        --i;
                        --endi;
                    }
                    break;
                
                case(UP):
                    if(i-1>=begini){//>=;有等於是因為begini是從0開始, index base
                        --i;
                    }else{
                        action = RIGHT;
                        ++j;
                        ++beginj;
                    }
                    break;
                default:
                    break;
                /*
            case(RIGHT):
                    if(j+1<endj){//???
                        ++j;
                    }else{
                        action = DOWN;
                        ++i;
                        ++begini;
                    }
                break;
                
                case(DOWN):
                    if(i+1<endi){
                        ++i;
                    }else{
                        action = LEFT;
                        --j;
                        --endj;
                    }
                break;
                
                case(LEFT):
                    if(j-1>=beginj){
                        --j;
                    }else{
                        action = UP;
                        --i;
                        --endi;
                    }
                break;
                
                case(UP):
                    if(i-1>begini){
                        --i;
                    }else{
                        action = RIGHT;
                        ++j;
                        ++beginj;
                    }
                break;
            default:
                break;
        */        
                    
        }
    }    
    return res;  
}
};

//======
vector<int> helper1(vector<vector<int>>& matrix){
    vector<int> res;
    int m = matrix.size(), n = matrix[0].size();
    int cnt = 0;
    int rmin=0,rmax=m-1;
    int cmin=0,cmax=n-1;
    enum{LEFT,RIGHT,UP,DOWN};
    int action = RIGHT;
    int i = 0, j = 0;
    
//先寫,再移動    
    while(cnt<m*n){
        res.push_back(matrix[i][j]);
        if(++cnt<m*n){
            switch(action){
                case(RIGHT):
                    if(j+1<=cmax){
                        j++;
                    }else{
                        i++;
                        rmin++;
                        action = DOWN;
                    }               
                break;
            
                case(LEFT):
                    if(j-1>=cmin){
                        j--;
                    }else{
                        i--;
                        rmax--;
                        action = UP;
                    }
                break;
            
                case(UP):
                    if(i-1>=rmin){
                        i--;
                    }else{
                        j++;
                        cmin++;
                        action = RIGHT;
                    }
                break;
            
                case(DOWN):
                    if(i+1<=rmax){
                        i++;
                    }else{
                        j--;
                        cmax--;
                        action = LEFT;
                    }
                    
                break;
            }
        }
    }
    return res;
}

//=== 寫法2 =====\
(*)用到 vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}}; 概念


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,0));
    int i=0,j=0;
    vector<int> res;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};//right(0),down(1),left(2),up(3)
    int direction_code = 0, total = m*n;

    while(total){    
        //先賦值
        res.push_back(matrix[i][j]);
        visited[i][j]=1;
        total--;

        //做update    
        int tmpi,tmpj;
        tmpi = i+dirs[direction_code][0];
        tmpj = j+dirs[direction_code][1];
        if(tmpi<0||tmpi>=m||tmpj<0||tmpj>=n||visited[tmpi][tmpj]){
            direction_code = (direction_code+1)%4;    
        }
        i=i+dirs[direction_code][0];
        j=j+dirs[direction_code][1];
        //if(visited[i][j]) break;
    }
    return res;
}

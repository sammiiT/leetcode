class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    int r = matrix.size();
    vector<int> res;
    if(r==0) return res;
    int c = matrix[0].size();
    enum Action{RIGHT,LEFT,UP,DOWN};
    Action action = RIGHT;
    
    //j??,i??
    int total = r*c;
    for(int i=0,j=0,begini=0,beginj=0,endi=r,endj=c,cnt=0;
       cnt<total;
       ++cnt){
                res.push_back(matrix[i][j]);
  
        switch(action){
                         case(RIGHT):
                    if(j+1<endj){
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
                    if(i-1>=begini){
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
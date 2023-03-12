//===類似題===
2212. Maximum Points in an Archery Competition
853. Car Fleet
1503. Last Moment Before All Ants Fall Out of a Plank
1776. Car Fleet II
//===思路===
(*)RL排列, RL都變成S => SS
-左邊的char變成S之後,必須判斷前面所有的char是否存在RS排列

(*)排列RS,R會變成S => SS
-左邊的char變成S之後,必須判斷前面所有的char是否存在RS排列

(*)排列SL,L會變成S => SS

//=====
void check_previous(vector<char>& stk, int& res){
    if(stk.size()==1) return;
    for(int i=stk.size()-2; i>=0; i--){
        if(stk[i]=='S') break;
        if(stk[i]=='R'){
            res+=1;
        }
    }
}
int countCollisions(string directions) {
    vector<char> stk;
    int res = 0;
    stk.push_back(directions[0]);
    for(int i=1;i<directions.size();i++){
        if(stk.back()=='R' && directions[i]=='L'){
                res+=2;
                stk.back()='S';
                directions[i]='S';  
                check_previous(stk,res);
           
        }
        else if(stk.back()=='R' && directions[i]=='S'){
                res +=1;
                stk.back()='S';
                check_previous(stk,res);    
        }
        else if(stk.back()=='S' && directions[i]=='L'){
                res+=1;
                directions[i]='S';
        }
//        else {
//        }
        stk.push_back(directions[i]);
    }
    return res;
}

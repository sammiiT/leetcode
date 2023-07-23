//===類似題===
718. Maximum Length of Repeated Subarray
89. Gray Code
//===思路===
(*)用stack做題
(*)如果可以形成2-digits, 將stack 做pop
- back()=1, 下一個數值為1或0

(*)如果形成00,01
- 將back()做pop, 再將下一個數值push至stack中

(*)如果stack最後是empty, 則是2-digits
    如果stack最後不是empty(單獨一個element, 此element等於0), 則1-digits

bool isOneBitCharacter(vector<int>& bits){
    vector<int> stk;
    for(int i:bits){
        if(stk.empty()){
            stk.push_back(i);
        }else{
            if(stk.back()==1 && (i==0||i==1)) {
                stk.pop_back();
            }
            else if(stk.back()==0 && (i==0||i==1)){
                stk.pop_back();
                stk.push_back(i);
            }
            else stk.push_back(i);
        }
    }
    return stk.empty()?false:true;
}


    
//===思路2====
bool isOneBitCharacter(vector<int>& bits) {
    int i=0;
    int res = 0;
    while(i<bits.size()){    
        if(bits[i]==1){
            i+=2;
        }else{
            if(i==bits.size()-1) res = 1;
            i+=1;
        }
    }
    return res;
}

//===思路2 改寫===
/*
one-bit = 0
two-bit = 11,10
看最後一個是否為one-bit
*/
bool isOneBitCharacter(vector<int>& bits) {
   int n=bits.size();
    int i;
    for(i=0; i<n-1;){//最後i停到 i=n-1, 則為one-bit
       if(bits[i]==1){
           i=i+2;
       }else{//bits[i]==0
           i=i+1;
       } 
    }
    return (i==(n-1));
}

//===類似題===
718. Maximum Length of Repeated Subarray
89. Gray Code
//===思路===

//====
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

//===思路2===
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

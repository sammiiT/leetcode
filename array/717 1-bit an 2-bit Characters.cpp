class Solution {
/*
one-bit = 0
two-bit = 11,10
看最後一個是否為one-bit
*/
public:
    bool isOneBitCharacter(vector<int>& bits) {
//------OK-------
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
};
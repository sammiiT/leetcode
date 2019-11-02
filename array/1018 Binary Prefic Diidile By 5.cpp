class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> res;
        // unsigned long cur=0;//若超過unsigned long的長度,會overflow,導致錯誤
        //                     //以x bits為一單位,建立pattern??
        int cur=0;
        if(n==0) return res;
        
        for(int i=0; i<n; ++i){
//Line 10: Char 23: runtime error: left shift of negative value            
            // cur = (cur<<1)|(unsigned long)A[i];
            
/*            
new = old*2 + digit
old = new%5;//以這一個去做判斷,且做為新的運算數值
*/      
            cur = (cur<<1)|A[i];
            // if(cur%5==0){//會有overflow情況發生
            if((cur=cur%5)==0){//關鍵
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};
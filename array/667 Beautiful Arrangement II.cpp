class Solution {
public:
//(1)產生n個數值;範圍1~n
//(2)兩兩相剪有k個相異的數值
    vector<int> constructArray(int n, int k) {
     
        int i=1,j=n;
        vector<int> res;
        while(i<=j){
            //k--%2 : 0,1,0,1...變化, 一下最左邊, 一下最右邊; k==0時, 就按照順序排列
            if(k>0) res.push_back(k--%2?i++:j--);
            else res.push_back(i++);
        }
        return res;
    }
};
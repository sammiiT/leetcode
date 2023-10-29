//===類似題===
923. 3Sum With Multiplicity
2149. Rearrange Array Elements by Sign
2164. Sort Even and Odd Indices Independently
//===思路===
1.建立兩個index, 一個是奇數index,一個偶數index
2.奇數index從1開始,偶數index從0開始
3.每次update index; 奇數+=2, 偶數+=2
4.遍歷數列並宣告一陣列來儲存上述判斷所得到的值
//===
vector<int> helper0(vector<int>& nums){
    int m = nums.size();
    int i=0,j=1;//i=even; j=odd
                 //i+=2,  j+=2
    vector<int> res(m);
    for(int a:nums){
        if(a%2){
            res[j]=a;
            j+=2;        
        }else{
            res[i]=a;
            i+=2;
        }
    }
    return res;
}
//===寫法2==
vector<int> sortArrayByParityII(vector<int>& nums) {
    vector<int> even;
    vector<int> odd;
    vector<int> res;
    int length =0;

    for(int i:nums){
        if(i%2) odd.push_back(i);
        else even.push_back(i);
    }

    length = odd.size()+even.size();
    for(int i=0; i<length; ++i){
        if(i%2){
            res.push_back(odd.back());
            odd.pop_back();
        }else{// 
            res.push_back(even.back());
            even.pop_back();
        }
    }
    return res;
}


//===思路2===
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> g;
        vector<int> o;
        vector<int> res;
        
        for(int i=0;i<A.size();++i){
            if(A[i]%2){//g
                g.push_back(A[i]);
            }else{//o
                o.push_back(A[i]);
            }
        }
        
        for(int i=0; i<A.size()/2; ++i){
            res.push_back(o[i]);
            res.push_back(g[i]);
        }
        return res;
        
    }
    
    vector<int> sortArrayByParityII_OK(vector<int>& A) {
        
        vector<int> even;
        vector<int> odd;
        vector<int> res;
        
        for(int i=0; i<A.size(); ++i){
            if(A[i]%2){//奇數
                odd.push_back(A[i]);
            }else{//偶數
                even.push_back(A[i]);
            }
        }
        
        int o=0,e=0;
        for(int i=0; i<A.size(); ++i){
            
            if(i%2){
                res.push_back(odd[o]);
                o++;
            }else{
                res.push_back(even[e]);
                e++;
            }
            
        }
        return res;
    }
};

//===類似題===
1353. Maximum Number of Events That Can Be Attended
634. Find the Derangement of An Array
695. Max Area of Island
1518. Water Bottles

//===思路===
(*)類似 陣列中每一個節點紀錄sum值
- [1,2,3,4,5] 
=>[1,3,6,10,15]


(*)此題利用上述蓋麵,陣列中,每一個節點紀錄product值
- [1,2,3,4,5]
=>[1,2,6,24,120]

(*)後面k個數值相乘:
- p[n-1]/p[(n-1)-k]
以上述範例, 前2個, p[5-1]/p[5-1-2] = p[4]/p[2] = 120/6=20;

=>如果只有兩個數[1,2]
前2個, p[2-1]/p[2-1-2] =>會發生p[-1], 所以必須在計算前須在p陣列前加上1
=>[1,1,2] ,所以 p[3-1]/p[3-1-2] = p[2]/p[0] 
(跟sum陣列有差異, 必須多加一個1,在陣列頭),"因為要除上兩數值的前一個數"

(*)如果遇到0 ,如[1,2,0,4,5] 
必須將p陣列清除重算, 並在題目發生0的點,重新作為p[0]=1; 所以
p=[1,1,2,1,4,20] => p[1,4,20]
    \     \---原本出現0的地方,算0
     \---多加的"1"   
        
當k>=p.size(), 則回傳0
當k<p.size(), 則 p[n-1]/p[n-1-k]

//=====
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        prod.push_back(1);
        res = 1;
    }
    
    void add(int num) {
        res*=num;
        if(res==0){
            res = 1;
            prod.clear();
            prod.push_back(res);
        }else{
            prod.push_back(res);
        }
    }
    
    int getProduct(int k) {
        if(k>=prod.size()){
            return 0;
        }
        else{
            //return prod.back()/prod[prod.size()-1-k];
            return prod[prod.size()-1]/prod[prod.size()-1-k];
        }
    }
private:
    vector<int> prod;  
    int res;  
};



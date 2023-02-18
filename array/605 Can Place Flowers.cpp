//===類似題===
606. Construct String from Binary Tree
495. Teemo Attacking
//===思路===
1.將數列前後分別加上一個"0" 
flowerbed.insert(flowerbed.begin(),0); //前面加上一個0
flowerbed.push_back(0);//最後加上一個0

2.從index =1開始判斷 ,一直到 index<flowerbed.size()-1; (index = flowerbed.size()-2)
3.此區間判斷不會超過陣列最大值
4.如果第i個是"0", 則判斷 (i-1)和(i+1)是否等於"0" ;如果是0,則可以插入1
5.以此判斷到 flowerbed.size()-2; 總共的1的數目和n比較,滿足題意則回傳true
//===
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int res = 0;
    flowerbed.insert(flowerbed.begin(),0);
    flowerbed.push_back(0);
    for(int i=1;i<flowerbed.size()-1;i++){
        if(flowerbed[i]==0){
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0) {
                res++;
                flowerbed[i]=1;
            }        
        }
    }
    return (res>=n);
}
//====
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        int res=0;
        if(flowerbed[0]==0) 
            flowerbed.insert(flowerbed.begin(),0);
        
        if(flowerbed[flowerbed.size()-1]==0)
            flowerbed.push_back(0);
        
        //for(int i=0;i<=flowerbed.size();++i){
         for(int i=0;i<flowerbed.size();++i){   
            if(i<flowerbed.size() && flowerbed[i]==0) cnt++;
            else{
                res = res +(cnt-1)/2;
                cnt=0;
            }
        }
        res = res +(cnt-1)/2;
        
        
        return res>=n;
    }
};

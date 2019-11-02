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
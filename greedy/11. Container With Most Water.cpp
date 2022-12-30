//===類似題=====
12. Integer to Roman
42. Trapping Rain Water
2517. Maximum Tastiness of Candy Basket

//===思路====
1.從左右兩端開始判斷起
2.左邊高 < 右邊高=> 用左邊求面積, 之後左邊往後移一格
2.2反之,若右邊, 求得面積後, 右邊界往前移一格
3.停止運算條件,當左邊界>=右邊界 ,則停止運算

//===
int helper0(vector<int>& height){
    int l=0,r=height.size()-1;
    int res = 0;
    while(l<r){
        int area = 0;
        if(height[l]<height[r]){
            area = (r-l)*height[l];
            ++l;
        }else{//height[l]>=height[r]
            area =(r-l)*height[r];
            --r;
        }
        res = max(res,area);
    }
    return res;    
}

int maxArea(vector<int>& height) {
        return helper0(height);
}

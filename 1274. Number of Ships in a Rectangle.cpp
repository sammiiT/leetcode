//===思路===
(*)divided and conquer
用2分法分割,分割到最小, 然後判斷是否有ship

int divideAndConquer(Sea sea, vector<int> bottomLeft, vector<int> topRight){
    if(topRight[0]<bottomLeft[0] || topRight[1]<bottomLeft[1] || !sea.hasShips(topRight,bottomLeft)) return 0;

   //sea.hasShips(topRight,bottomLeft)
    if(topRight[0]==bottomLeft[0] && topRight[1]==bottomLeft[1]) return 1; 
    
    int cnt = 0;
    int midx = bottomLeft[0] + (topRight[0]-bottomLeft[0])/2;
    int midy = bottomLeft[1] + (topRight[1]-bottomLeft[1])/2;
    
    cnt += divideAndConquer(sea,bottmLeft, {midx,midy});
    cnt += divideAndConquer(sea,{midx+1,midy+1}, topRight);
    cnt += divideAndConquer(sea,{midx+1,bottomLeft[1]}, {topRight[0],midy});
    cnt += divideAndConquer(sea,{bottomLeft[0],midy+1},{midx,topRight[1]});

    return cnt;
}

int countShips(Sea sea, vector<int> bottomLeft, vetor<int> topRight){
    return dividedAndConquer(sea,bottomLeft,topRight);
}

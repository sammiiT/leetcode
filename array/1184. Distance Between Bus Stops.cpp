//===類似題===
1186. Maximum Subarray Sum with One Deletion
2361. Minimum Costs Using the Train Line
//===思路===
1.遍歷一次數列,紀錄start-->destination總和 以及 destination->(start+n-1)%n (start的前一個位置) 的總和
2.概念: start的前一個index是 (start+n-1)%n
  以題目陣列條件: 從start走到destination, 是紀錄start到(detsination-1)的總和
 
  0------>1
  ^       |  
  |       v
  3<------2
    
//=====
int helper0(vector<int>& distance, int start, int destination){
    int flag =1;
    int i = start;
    vector<int> res(2,0);//
    int tmp=0;
    int n = distance.size();

    while(flag){//判斷是否走到start的前一個, 走到start的前一個, 就要跳出
        if(i==destination){//走到 destination, 要記錄之前的總和
            res[0]=tmp;//紀錄之前的總和
            tmp =0;//重新reset
        }
/*        else if(i==(start+(n-1))%n){//當destination的下一個是start, 此描述會執行不到, 造成錯誤
            flag = 0;
        }*/        
        if(i==(start+(n-1))%n) flag=0;
        
        tmp +=distance[i];//記錄每一次的距離
        i=(i+1)%n;//跳下一格
    }
    res[1]=tmp;//從destination到 start的前一個位址
    return min(res[0],res[1]);//比較誰比較小,回傳小的值
}

    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        return helper0(distance,start,destination);
    }

//======
當點在(start, destination)內 , 就累加到sum1, 沒有就累加到sum2
要注意start要小於destination, 開始做比較,如果start>destination, 則兩者做交換, 最後返回sum1, sum2較小的即可
int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum1 = 0, sum2 = 0, n = distance.size();
        if (start > destination) swap(start, destination);
        for (int i = 0; i < n; ++i) {
            if (i >= start && i < destination) {
                sum1 += distance[i];
            } else {
                sum2 += distance[i];
            }
        }
        return min(sum1, sum2);
}



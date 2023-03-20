//===類似題===
1095. Find in Mountain Array
253. Meeting Rooms II
//===思路====
1.記錄每一個站點的上車,和下車人數
[2,1,5] => 站1上車2人, 站5下車2人
        => [1,2] ,[5,-2]
        
2.遍歷trips陣列,並將每一站的上下車人數作紀錄, 產生"上下車vector<vector<int>>陣列"
-此陣列比需重新作排列, 依據每一站的順序作排列
  
3.遍歷上述紀錄的陣列,將每一站的人數作累加
-如果超出capacity則回傳false
-遍歷完代表可以滿足capacity,回傳true

//======
bool helper0(vector<vector<int>>& trips, int capacity) {
    vector<vector<int>> people;

    for(auto a:trips){
        people.push_back({a[1],a[0]});//站1上來了a[0]個人
        people.push_back({a[2],-a[0]});//站2下去了a[0]個人
    }
    sort(people.begin(),people.end());
    int p=0;
    for(auto a:people){
        p+=a[1];//每一站上上下下的總和
        if(p>capacity) return false;//如果某一站大於capacity
    }
    return true;
}

//===思路2===
(*)上述中途要做一次排列,不夠效率
(*)0 <= fromi < toi <= 1000 所以有1001個站; 0,1,2,...1000
1.宣告陣列,表示每一站的"上下車總人數"
- index = 站
- [index] = 總數

2.遍歷trips陣列, 累加"個別站"的上下車總人數   
3.從0~1000站, 累加所有的上下車總人數
-如果超出capacity則回傳false
-遍歷完代表可以滿足capacity,回傳true

bool helper1(vector<vector<int>>& trips, int capacity) {
    vector<int> cnt(1001);//1001 stops
    int p=0;
    for(auto a:trips){
        cnt[a[1]]+=a[0];//需累計,因為會從同樣一個點出發
        cnt[a[2]]-=a[0];//需累計,因為會從同樣一個點下車
        //這邊的累加,是同一站的上下車累加, 之後會考慮前面上下車的人數累加
    }

//    for(int i=0;i<=1000;i++){
    for(int i=0;i<=1000;i++){
        p+=cnt[i];
        if(p>capacity) return false;
    }
    return true;
}

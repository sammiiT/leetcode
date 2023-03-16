//===類似題===
854. K-Similar Strings
1776. Car Fleet II

//===思路===
(*)變因有兩個, 一個速度,一個位址=> 以比例計算,做比較,可以建立在同一基準上討論
-以時間來算, 可以將所有變因建立在同一基準上
-以距離target最近的開始計算起,以此做為比較的基準點
--可以追到距離target最近的汽車, 當作一個group
--如果時間大於位置最前面的車,代表沒辦法追上, fleet要加1,並更新時間; 代表新的fleet group
--如果時間小於位置最前面的車,代表可以追上, 在同一個fleet group


1.建立map<int,double>//距離target位置,所需要的距離
- map<key,value>在遍歷時,會依照key的大小作排列(ascending)
-將position取負值,則第一個就是距離target最近的位址
--position [10,8,0,5,3] => map[-10,-8,-5,-3,0]第一個距離target最近的值.
  
(*)全部都是以,後面的車是否能追上前面的車 作為判斷依據; 
-後面的車時間小於 前面的車 ,代表可以追到
-後面的車時間大於 前面的車, 代表不能追到  
//=======
int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int fleet = 0;
        map<int,double> mp;//position, time
        for(int i=0; i<n; i++){
            mp[-position[i]] = (double)(target-position[i])/speed[i];
        }
//        int time = 0;
        double time=0;
        for(auto a: mp){
            if(a.second<=time) continue;//時間小於前面的車, 可以追上, 代表是在同一個fleet上
            time = a.second;//時間大於前面的車, 代表沒辦法追上, 是在另外一組fleet group上
            fleet++;
        }
        return fleet;
}

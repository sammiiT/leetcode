//===類似題===
782. Transform to Chessboard
1547. Minimum Cost to Cut a Stick
656. Coin Path
1418. Display Table of Food Orders in a Restaurant

//===思路===
(*) 概念是Greedy
(*)  
[2,2,2]
r有三個,當好問到這三個的回 => [2,2,2] 
r有三個,只問到一個 => [2]
r有三個,只問到二個 => [2,2]

=> 出現一個數值 a, 則至少有(a+1)隻rabbit;
=> 有可能會問到同一顏色的rabbit, 所以數值a在陣列中,最多會出現(a+1)次;最少會出現1次
=> 如果超過a出現的次數,超過(a+1)次, 則此a是新的顏色
[2,2,2,2],前面3次是相同顏色, 第4個是不同顏色

1.unordered_map<int,int> 紀錄每一個val出現的次數 count
2.遍歷map,判斷其個數
for(auto a:mp){
    int ans = a.first;
    int ansCnt = a.second;

    int colors = ansCnt/(ans+1);
    int remain = ansCnt%(ans+1);

    res = res + colors*(ans+1)+ (remain>0)*(ans+1); 

} 
//====
int numRabbits(vector<int>& answers) {
    unordered_map<int,int> mp;
    int res = 0;

    for(int a:answers) mp[a]++;
    for(auto a:mp){
        int ans = a.first;
        int ansCnt = a.second;
        int colors = ansCnt/(ans+1);
        int remain = ansCnt%(ans+1);
        res = res + colors*(ans+1)+(remain>0)*(ans+1);
    }
    return res;
}

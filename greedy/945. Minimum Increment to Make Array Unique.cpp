//===類似題===
946. Validate Stack Sequences
2233. Maximum Product After K Increments
//===思路1====
(*)依據題意, 每一個數加1, 代表一個movement, 求總共的movement, 讓數列每一個數值不相等
(*)利用map<int,init>; (value, count)
-不用unordered_map<int,int>, 因為不會對key作排列;會出錯

1.遍歷數列,並用map<int,int>記錄每一個數出現的個數
2.遍歷map<int,int>,若數值出現的次數大於1
- 多於的個數累加到 [a.first+1]的個數中;  也同時累加到movement中
- 並將原本[a.first]的個數修正為1
//=====
int minIncrementForUnique(vector<int>& nums) {
    map<int,int> mp;
    int res = 0;
    for(int a:nums) ++mp[a];
    
    for(auto a:mp){
        int t;
        if(a.second>1){
            t = a.second-1;
            res += t;
            mp[a.first+1]+=t;
            mp[a.first]=1;
        }
    }    
    return res;    
}

//===思路2===
int minIncrementForUnique(vector<int>& A) {
    int res = 0, need = 0;
    map<int, int> numCnt;
    for (int num : A) ++numCnt[num];
    for (auto &a : numCnt) {
     	res += a.second * max(need - a.first, 0) + a.second * (a.second - 1) / 2;
    	need = max(need, a.first) + a.second;
    }
    return res;
}

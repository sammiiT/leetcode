//===類似題===
2315. Count Asterisks
2391. Minimum Amount of Time to Collect Garbage
1498. Number of Subsequences That Satisfy the Given Sum Condition
1121. Divide Array Into Increasing Sequences

//===思路====
(*)如果用int來計算, 會overflow
(*)用long long來銜接int數值,做累加
//=====
bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    long long cnt = mass;
    sort(asteroids.begin(),asteroids.end());
    for(int num:asteroids){
        if(cnt>=num){
            cnt+=num;
        }else{//mass<num
            return false;
        }
    }
    return true;
}


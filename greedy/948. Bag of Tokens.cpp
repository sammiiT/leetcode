//===類似題===
949. Largest Time for Given Digits
2071. Maximum Number of Tasks You Can Assign
500. Keyboard Row
1333. Filter Restaurants by Vegan-Friendly, Price and Distance
//===思路===
(*)題目並沒有說要順序遍歷, 只說選取, 所以可以先將數列做排列, 開始選取
(*)greedy概念
(*)將tokens[i]作排列(ascending)

- tokens[i]在小的時候,用power換points
- tokens[i]在大的時候,用points換power
  
(*)求解過程中, 可以獲得points的最大值, 一直到所有的token都拜訪完, 回傳最大值

//====
int bagOfTokensScore(vector<int>& tokens, int power) {
    int res=0, points=0;
    int i=0, j = tokens.size()-1;
    sort(tokens.begin(),tokens.end());
    while(i<=j){
        while(i<=j && power>=tokens[i]){
            power-=tokens[i];
            res = max(res,++points);
        }
        if(points==0 || i>j) break;
        points--;
        power-=tokens[i];
    }
    return res;
}

//=======
(*)score換最大的 value
(*)power換最小的 value;
(*)每次計算完都紀錄一次最大的score
-res = max(res,score)
  
int bagOfTokensScore(vector<int>& tokens, int power) {
    int res = 0,score = 0;
    int l = 0,r = tokens.size()-1;
  
    sort(tokens.begin(),tokens.end());
    if(tokens[l]>power) return 0;
    
    while(l<=r){//如果(l<r)會少計算一次
                //先運算,再更新 => 所以要(l<=r)
        if(power>=tokens[l]){
            power-=tokens[l];
            score+=1;
            ++l;
        }else if(score>0){
            power+=tokens[r];
            score-=1;
            --r;
        }
        res = max(res,score);
    }
    return res;
}



int bagOfTokensScore(vector<int>& tokens, int power) {
    int res = 0, points = 0;
    int i=0,j=tokens.size()-1;
    
    sort(tokens.begin(),tokens.end());
    while(i<=j){
        if(power>=tokens[i]){
            power-=tokens[i];
            i++;
            res = max(res,++points);
        }else if(points>0){
            power+=tokens[j];
            j--;
            points-=1;
        }else{//i>j
            break;
        }
    }
    return res;
}

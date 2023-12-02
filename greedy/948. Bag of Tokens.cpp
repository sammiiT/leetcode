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

//====寫法2===
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
//====寫法3===
(*)每一個位置的index都要計算
1.先做ascendding排列
2.設定邊界索引, l從0開始, r從size()-1開始; 設定停止條件 (l<r)
3.將power全部一次換成score (由小到大) ; l++
4.如果power不足, 就從陣列的back(), 用score換成power ; r--
5.當(l==r)時; 判斷最後一個還沒操作的數值
-如果power>=tokens[r] ,代表可以score可以再+1

int bagOfTokensScore(vector<int>& tokens, int power) {
    int l =0, r = tokens.size()-1;
    int score = 0;//, res = 0;
    sort(tokens.begin(),tokens.end());
    while(l<r){
        if(power>=tokens[l]){
            power-=tokens[l];
            l++;
            score++;
            continue;
        }
        if(score){
            power+=tokens[r];
            r--;
            score--;
            continue;
        }
        break;
    }
    if((r==l) && (power>=tokens[r]))
        score++;//res++;
    return score;
}


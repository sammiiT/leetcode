//===類似題===
1423. Maximum Points You Can Obtain from Cards
415. Add Strings
2207. Maximize Number of Subsequences in a String
536. Construct Binary Tree from String
//===思路==
(*)左邊0越多越好, 右邊1越多越好
(*)遍歷第一次, 紀錄"1"的總數.
(*)遍歷第二次, 若1, 右半邊的1就從總數去掉;若0,就將0個數記錄下來; 左半0+右半1
- 遍歷次數為string.size()-1; 因為題意, 要split, 所以不能左邊0個數字或右邊0個數字

(*)遍歷時對每一次結果做maximum比較 
 
//=== 
 int helper1(string s){
    int cnt1=0;
    int cnt0 = 0;
    int res = 0;
    for(int i=0;i<s.size();i++)
        if(s[i]-'0') cnt1++;//maximum "1" count

    for(int i=0;i<s.size()-1;i++){
        if(s[i]-'0') cnt1--;
        else cnt0++;
        res = max(res,cnt0+cnt1);
    }
    return res;
}
//====
int helper0(string s){
    int cnt0=0,cnt1=0;
    int res = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') cnt1++;
    }

    for(int i=0;i<s.size()-1;i++){//i<s.size()會出錯, [00],沒有split
        if(s[i]=='1') {
            cnt1--;
        }else if(s[i]=='0'){
            cnt0++;    
        }
        res = max(res,cnt0+cnt1);
    }
    return res;        
}

int maxScore(string s) {
    return helper0(s);    
}

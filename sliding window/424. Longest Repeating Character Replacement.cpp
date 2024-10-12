//===類似題====
425. Word Squares
340. Longest Substring with At Most K Distinct Characters
2009. Minimum Number of Operations to Make Array Continuous
2024. Maximize the Confusion of an Exam

//===思路====
(*)sliding window求算
(*)window範圍內的所有字母,先取出現最多的那一個; "所有字母"減去"出現最多的那一個", 剩下的字母數,就是可以被取代(replace)的個數
1.如果剩下replace的個數>題目給的k => 要移動window_left, 一直到replace個數==題目k
2.每次求算都會計算一次最長的解

3.遍歷完數列, 回傳最長的解

//=====

int helper0(string s, int k){
    int mx = 0;
    int start = 0;
    int res = 0;
    vector<int> count(26,0);

    for(int i=0;i<s.size();i++){
        mx = max(mx, ++count[s[i]-'A']);//計算字母出現最多的次數,以此次數來求解
        while((i-start+1)-mx > k){//移動window_left, 並將對應的count數減1
            --count[s[start]-'A'];//將對應的count數減1
            ++start;//移動window_left
        }
        res = max(res,i-start+1);//計算一次最長的數值
    }
    return res;
}
int characterReplacement(string s, int k) {
        return helper0(s,k);
}
//=== 寫法2 ===
(*)使用unordered_map<char,int> 紀錄character出現個數

AABABBBB  k=1

    
int characterReplacement(string s, int k) {
    int i=0, j=0, n=s.size();
    unordered_map<char,int> ump;
    int mx = 0, res = 0;
    
    for(; i<n; ++i) {
        ump[s[i]]++;
        mx = max(mx,ump[s[i]]);

/*
為什麼不用更新的maxCnt?
maxCnt相當於卡了一個窗口大小,  
我們並不希望窗口變小, 雖然窗口在滑動, 但之前是出現過跟窗口大小相同符合題意子串,
縮小窗口沒有意義, 並不會使結果res變大, 所以我們才不更新maxCnt        
*/
        while((i-j+1)-mx > k){// 在不同區間內, 減去一個固定的值 ----> 很難思考
            ump[s[j]]--;
            if(ump[s[j]]==0) ump.erase(s[j]);
            j++; //j++ ; j的移動,
        }
        res = max(res,i-j+1);
    }
    return res;
}

    





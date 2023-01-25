//===類似題====
425. Word Squares
340. Longest Substring with At Most K Distinct Characters
2009. Minimum Number of Operations to Make Arr

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

//===類似題===
4. Median of Two Sorted Arrays
159. Longest Substring with At Most Two Distinct Characters
340. Longest Substring with At Most K Distinct Characters
992. Subarrays with K Different Integers

//===思路===
1.遍歷數列
2.用unordered_map紀錄每一個出現字母出現的最後位置
3.用變數left紀錄下一次substring長度的起始位置, left是會因為字母重複出現而改變

//====
int helper1(string s){
    int n = s.size(),ret=0,left = -1;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        if(m.count(s[i])&& m[s[i]]>left){
            left = m[s[i]];
        }
        m[s[i]]=i;//每次都記錄字母出現的最後位置
        ret = max(ret,i-left);//每次都計算最長的substring大小
    }       
    return ret;
}


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
//===思路2===
(*)sliding_window解法
-遇到第一個重複(第二次出現),則將第一次出現(包含第一次出現之前的所有數值)刪除
           (1)第一個重複                          (1)第一個重複(第二次出現) 
          /                                      /
a  b  c  a  b  c  b  b           a  b  c  d  e  d  a  c  
 \                                \  \  \  \
2)刪                             2)刪 刪 刪 刪  

//====
int helper2(string s){
    unordered_map<char,int> m;
    int res = 0;
    int i=0,left=0;
    int n = s.size();

    while(i<n){
        if(!m.count(s[i])){//如果沒有出現過的character
            m[s[i]]=i;//紀錄出現位址
            res = max(res,i-left+1);//計算最長數值
            i++;//更新index
            continue;
        }
//     for(;left<i;left++){ m.erase(s[left]); }
        int first = m[s[i]];
        for(; left<=first; left++) m.erase(s[left]);//開始sliding window計算,計算完之後left也更新其位置index
        m[s[i]]=i;//重新紀錄s[i]出現的位址
        i++;//index更新
    }
    return res;
}

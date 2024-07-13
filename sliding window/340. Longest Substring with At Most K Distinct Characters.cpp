//===類似題===
159. Longest Substring with At Most Two Distinct Characters
//===思路====
(*)sliding window
1. i=window_right, j=window_left;
2. 利用unordered_map紀錄每一個char出現的次數
3.每次出現一個不一樣的char, 則k--;
4.如果k<0,代表超過題目條件,要移動window_left
如果k>=0,代表未超出題目條件,計算最大長度

5.遍歷數列,並依照上述規則求出最大長度

//========
int lengthOfLongestSubstringKDistinct(string s, int k){
    unordered_map<char,int> m;//character, count
    int n = s.size();
    int j = 0, res = 0;
    
    for(int i=0; i<n; i++){
        if(m.find(s[i])==m.end()) k=k-1;
        m[s[i]]++;
        
        if(k>=0) res = max(res, i-j+1);
        
        while(k<0){
            m[s[j]]--;//每次移除一個char
            if(m[s[j]]==0) {//如果map中對應的char次數為0,則把此key從map中移除
                m.erase(s[j]);
                k++;//key從map移除之後, k加1;讓substring滿足題意
            }
            j++;//移動window_left
        }
    }
    return res;
}
//===思路2===
1.跟上述解法一樣,但不對k做減法運算
//=========
int lengthOfLongestSubstringKDistinct(string s, int k){
    unordered_map<char,int> m;
    int res = 0, j =0, n=s.size();
    
    for(int i=0;i<n;i++){
        m[s[i]]++;
        
        while(m.size()>k){
            m[s[j]]--;
            if(m[s[j]]==0) m.erase(s[j]);
            j++;
        }
        res = max(res,i-j+1);
    }
    return res;   
}

//=== 寫法3 ===
(*)用multiset<int> 和 set<int>

int lengthOfLongestSubstringKDistinct(string s, int k){
    multiset<int> mst;
    set<int> st;
    int j=0, res = INT_MIN;
    
    for(int i=0;i<s.size();++i){
        mst.insert(s[i]);
        st.insert(s[i]);
        if(st.size()>k){
            mst.erase(mst.equal_range(s[j]).first);
            if(mst.count(s[j])==0){
                st.erase(s[j]);
            }
            ++j;
        }
        res = max(res,i-j+1);
    }
    return res;
}



    

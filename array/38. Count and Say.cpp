//===類似題====
39. Combination Sum
271. Encode and Decode Strings
443. String Compression
//===思路====
1.每一loop紀錄了前一個string的念法
2.雙迴圈, 最上層的迴圈是計算每一個數字的念法
3.最下層迴圈是計算念法
//======
string helper0(int n){
    if(n==1) return "1";    

    string pre = "1#";//1
    string res;
    int same;
    
    for(int i=2; i<=n; i++){
        res="";//每一次都要做reset, 沒有reset會錯誤
        same = 1;
        //如果pre="1",則最後一個算不到,所以強制加上一個非數字字元
        
        for(int j=1; j<pre.size(); j++){//counting
            if(pre[j]==pre[j-1]) same+=1;
            else{//pre[j]!=pre[j-1]; //不一樣才紀錄, 若全部都一樣??? 所以在最後加上一個"#"
                res = res + to_string(same)+pre[j-1];
                same =1;
            }
        }
        pre = res + "#";//每次運算的時候都加上一個非數字字元
    }
    return res;
}
string countAndSay(int n) {
        return helper0(n);
}

//=====failed===
(*)底下unordered_map方式錯誤
-[1121]會變成3112
-因為unordered_map存的"1",沒有被截斷, 所以會算出3個1
string helper1(int n){
    string s = "1";
    int i=2;
    unordered_map<int,int> m;
    vector<int> val;
    while(i<=n){
        for(char a:s){
            if(m.count(a-'0')) m[a-'0']++;
            else{
                m[a-'0']++;
                val.push_back(a-'0');
            }
        }
        s.clear();
        for(int a:val) s = s+ to_string(m[a])+ to_string(a);
        i++;
        val.clear();
        m.clear();
    }
    return s;
}


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
        res="";
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

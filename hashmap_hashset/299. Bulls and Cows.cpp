//===more challenge ===
2531. Make Number of Distinct Characters Equal
//===思路===
(*) unordered_map<> + set<>
1. 定義:
unordered_map<char,set<int>> ump;
<char,set<int>> = <數字,數字位置>

2. 紀錄secret和 guess數字出現的位置和對應的位置

3.以secret map為基準, 用guess map來比較, 出現的數字和位置是否有和secret有匹配
- 如果出現"數字相同" 且 "位置相同", 則計數 A
- 比較完, secret 和 guess 剩下"相同數的個數", 取個數最小值, 即為 B的數目
  B = min(scr[it.first].size()-A,gus[it.first].size()-A)
--其中"減A" 是"排除同位置的個數"  

string getHint(string secret, string guess) {
    unordered_map<char,set<int>> scr;
    unordered_map<char,set<int>> gus;
    string res;
    int A =0,B=0;
    
    for(int i=0; i<secret.size(); ++i){
        scr[secret[i]].insert(i);
        gus[guess[i]].insert(i);
    }
    
    for(auto it:gus){
        if(scr.count(it.first)){
            int a=0,b=0;            
            for(set<int>::iterator iter=it.second.begin(); iter!=it.second.end(); ++iter){
                if(scr[it.first].count(*iter)) a++;
            }
            b = min(scr[it.first].size()-a,it.second.size()-a);
            A+=a;
            B+=b;
        }
    }
    res = to_string(A)+'A'+to_string(B)+'B';
    return res;
}

//===思路2===
string getHint(string secret, string guess) {
    unordered_map<char,int> scr;
    unordered_map<char,int> gus;
    int A=0,B=0;
    
    for(int i=0;i<secret.size();++i){
        if(secret[i]==guess[i]){
            A++;
        }else{
            scr[secret[i]]++;
            gus[guess[i]]++;
        }
    }

    for(auto it:gus){
        char ch = it.first;
        int count = it.second;
        B = B+min(count,scr[ch]);
    }

   return to_string(A)+'A'+to_string(B)+'B';
}

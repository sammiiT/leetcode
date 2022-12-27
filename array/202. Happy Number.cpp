//===類似題===
203. Remove Linked List Elements
258. Add Digits
1945. Sum of Digits of String After Convert
2457. Minimum Addition to Make Integer Beautiful

//===思路====
1.如果不是Happy number, 會以如下模式重複出現
   4,16,37,58,89,145,42,20, 4....

2.用hash table 紀錄所有出現的數字, 如果出現重複, 則不是Happy number  
3.如果等於1則是Happy Number  
  
//======
int count(string s){
        int res=0;
        for(int i=0;i<s.size();i++)
            res +=(s[i]-'0')*(s[i]-'0');
        return res;
}
bool isHappy(int n) {
        string s = to_string(n);
        unordered_map<int,int> mp;
        int res = n;
        while(res!=1){
            res = count(s);
            if(mp.count(res)) return false;
            else ++mp[res];
            s = to_string(res);
        }        
        return true;
}

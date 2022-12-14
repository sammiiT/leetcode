//=======類似題==========
390. Elimination Game
2403. Minimum Time to Kill All Monsters
2056. Number of Valid Move Combinations On Chessboard
291. Word Pattern II


//===思路===
1.將s加入map
2.t與map做比對, 存在char則對map做減一;
3.如果m對應的element不存在, 即解
char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        char res;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(m[t[i]]==0){ res = t[i];        
            }else{m[t[i]]--;}
        }
/*  加入map中的element, 除了用erase之外; 沒有其他方法可以將其刪除
    m[t[i]]--是對map中t[i]這個element做運算,不會刪除,所以用find(), count(), 此element仍然存在 
        for(int i=0;i<t.size();i++){
            if(m.find(t[i])==m.end()){
                res = t[i];        
            }else{
                m[t[i]]--;
            }
        }*/

/*   可以有重複,所以不能用此方法
        for(int i=0;i<t.size();i++){
            if(m.count(t[i])) continue;
            res =  t[i];
        }*/
        return res;
    }
    
//=====    
char findTheDifference(string s, string t) {
       int sum1=0,sum2=0;
       for(int i=0;i<s.size();i++){
          sum1+=s[i];
       } 
       for(int i=0;i<t.size();i++){
          sum2+=t[i];
       }
       char res=char(sum2-sum1);
       return res;
}


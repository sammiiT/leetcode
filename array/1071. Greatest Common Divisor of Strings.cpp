//===類似題===
1072. Flip Columns For Maximum Number of Equal Rows
2413. Smallest Even Multiple

//===思路===

//======
string helper(string str1,string str2){
    int s1,s2;
    while(str2.size()!=0){
        string tmp;
        s1 = str1.size(), s2 = str2.size();
        for(int i=0;i<(s1-s1%s2)/s2;i++)  
            tmp+=str2;
        
        if(str1.substr(0,s1-s1%s2)!=tmp)  
            return "";
        tmp = str2;
        str2=str1.erase(0,s1-s1%s2);
        str1 = tmp;
    }
    return str1;
}
string gcdOfStrings(string str1, string str2) {
        string s1, s2;
        if(str1.size()>=str2.size()) { s1 = str1; s2=str2;}
        else { s2 = str1; s1=str2;}
        return helper(s1,s2); 
}

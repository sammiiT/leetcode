//===類似題====
985. Sum of Even Numbers After Queries
2063. Vowels of All Substrings
472. Concatenated Words
792. Number of Matching Subsequences

//===思路===


//=======
string strWithout3a3b(int a, int b) {
    string res;
    char l = 'a';
    char s = 'b';
    
    if(b>a){
        l = 'b';
        s = 'a';
        int t = a;
        a = b;
        b = t;
    }
    
    while(a&&b){
        res+=string(1,l);
        res+=string(1,s);
        a--;
        b--;
    }
    
    for(int i=0; i<res.size(); i++){
        if(res[i]==s){
            if(a--){
                res.insert(res.begin()+i,l);
                i++;
            }else break;
        }
    } 

    for(int i=0 ; i<2 && a>0; a--){//last
        res+=string(1,l);
    }
    return res;  
}

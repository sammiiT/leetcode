//===類似題===
2376. Count Special Integers
942. DI String Match

//===思路====


//====
string smallestNumber(string pattern) {
    int n = pattern.size();
    string res;
    for(int i=1; i<=n+1 ;i++)  { res+=(char)(i+'0'); }      
    for(int i=0;i<n;i++){
        if(pattern[i]=='D'){
            int j=i+1;
            while(j<n && pattern[j]=='D') ++j;
            reverse(res.begin()+i,res.begin()+j+1);
            i=j-1;
        }
        
    }
    return res;
}

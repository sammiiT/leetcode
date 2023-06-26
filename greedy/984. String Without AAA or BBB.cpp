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

//====思路====
(*)利用priority_queue 求解

string helper2(int a, int b) {
    priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
    string res;
    int cntx=0,cnty=0;
    pq.push({'a',a});
    pq.push({'b',b});
    
    while(pq.size()>=2){
        pair<char,int> x = pq.top();pq.pop();
        pair<char,int> y = pq.top();pq.pop();
        
        if(x.second-y.second>=1){
            cntx = 2;
            cnty = 1;
        }else if(x.second-y.second==0){
            cntx = (x.second>=2)?2:1;
            cnty = cntx;
        }
        res = res + string(cntx,x.first);
        res = res + string(cnty,y.first);
        x.second-=cntx;
        y.second-=cnty;
        if(x.second>0) pq.push({x.first,x.second});
        if(y.second>0) pq.push({y.first,y.second});
    }
    if(pq.size()==1){
        pair<char,int> t = pq.top();pq.pop();
        cntx = t.second>=2?2:1;
        res = res +string(cntx,t.first);
    }
    return res;
}



//===類似題===
1944. Number of Visible People in a Queue
2389. Longest Subsequence With Limited Sum
745. Prefix and Suffix Search
253. Meeting Rooms II

//===思路===
可參考 984. String Without AAA or BBB

(*)Greedy, 有多少,拿多少;但此題不能一次取
- 一次只能排一個, 但優先排列的,還是最多的那一個

(*)建立此string最多要執行(a+b+c)次, 每遍歷一次, 放一個字元到string中
(*)每一個字元不能重複出現兩個,所以要再宣告三個變數,用來計算連續出現的次數



(*)"至少間隔", "最多不能重複"
Task Schedule題目, 屬於"至少間隔"類型, 每一個字元要"盡可能地遠離"
Longest Happy String題目,屬於"最多不能重複"類型, 每一個字元要"盡可能地靠近"        
//===
string helper1(int a, int b, int c) {
        int A=0,B=0,C=0;
        string res;
        int n = a+b+c;
        for(int i=0; i<n; ++i){
            if((a>=b&&a>=c&&A!=2)||(a>0 && B==2)||(a>0&&C==2)){
                res+='a';
                a--;
                A++;
                B=0;
                C=0;
            }else if((b>=a&&b>=c&&B!=2)||(b>0 && A==2)||(b>0&&C==2)){
                res+='b';
                b--;
                B++;
                A=0;
                C=0;
            }else if((c>=a&&c>=b&&C!=2)||(c>0 && A==2)||(c>0&&B==2)){
                res+='c';
                c--;
                C++;
                A=0;
                B=0;    
            }
        }
        return res;
    }

string longestDiverseString(int a, int b, int c) {
    return helper1(a,b,c);
}

//===思路2====

string longestDiverseString(int a, int b, int c){
    int cntx,cnty;
    string res;
    priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq; 
    if(a>0) pq.push({'a',a});
    if(b>0) pq.push({'b',b});
    if(c>0) pq.push({'c',c});

    while(pq.size()>=2){
        pair<char,int> x = pq.top();pq.pop();
        pair<char,int> y = pq.top();pq.pop();
        
        if(x.second-y.second>=2){//個數差2
            cntx = 2;
            cnty = 1;
        }else if(x.second-y.second==1){//個數差1
            // oox   
            if(x.second<=2 && y.second<=1){
                cntx = 2;
                cnty = 1;
            }
            //ooo xx
            if(x.second>2 && y.second >1){
                cntx = 2;
                cnty = 2;
            }
        }else{//x.second==y.second
            if(x.second==2 && y.second==2){//個數差0
                cntx = 2;
                cnty = 2;
            }else{//x.second==1 && y.second==1
                cntx = 1;
                cnty = 1; 
            }           
        }

        res = res +string(cntx,x.first);
        res = res +string(cnty,y.first);
        x.second -=cntx;
        y.second -=cnty;
        if(x.second>0) pq.push({x.first,x.second});
        if(y.second>0) pq.push({y.first,y.second});
    }

    if(pq.size()==1){
        pair<char,int> x = pq.top();pq.pop();
        cntx = (x.second>=2)?2:1;
        res = res + string(cntx,x.first);
    }
    return res;
}







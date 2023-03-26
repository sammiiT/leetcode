//===類似題===
1944. Number of Visible People in a Queue
2389. Longest Subsequence With Limited Sum
745. Prefix and Suffix Search
253. Meeting Rooms II

//===思路===
(*)Greedy, 有多少,拿多少;但此題不能一次取
- 一次只能排一個, 但優先排列的,還是最多的那一個

(*)建立此string最多要執行(a+b+c)次, 每遍歷一次, 放一個字元到string中
(*)每一個字元不能重複出現兩個,所以要再宣告三個變數,用來計算連續出現的次數



(*)"至少間隔", "最多不能重複"
Task Schedule題目
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


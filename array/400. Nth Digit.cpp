//==== 類似題 ====
401. Binary Watch
2468. Split Message Based on Limit
1118. Number of Days in a Month
1956. Minimum Time For K Virus Variants to Spread

//===思路===
(*) 
n為剩下的個數, 個數(想像為nums.size())
要計算數列的位址,必須 (n-1)來計算
ex: n=6
計算位址=> [0,1,2,3,4,5]
5/3 = 1...2
從group index 1開始, 此group中的index 2,就是等於5
group0 = [0,1,2], group1=[3,4,5];

(*)如果6/3=2, 只能知道有兩個group


//===
int helper0(int n){//n就是第n個digit
/*
len位數, cnt特定位數區間的總個數, start紀錄n在位數區間的起始值 */
        long len = 1, cnt = 9, start = 1;
        string res;

        while(n>len*cnt){//len*cnt = 位數 * 區間總個數
            n = n-len*cnt;
            ++len;
            cnt = cnt*10;//90,900,9000
            start = start*10;//10,100,1000,...
        }
//      n =  剩下的個數
        start = start + (n-1)/len;
        res = to_string(start);
        return res[(n-1)%len]-'0';
/*
string = 321
(n-1)%len=2 => [0]=3,[1]=2,[2]=1;
取[2]=1
*/        
}

int findNthDigit(int n) {
        return helper0(n);
}

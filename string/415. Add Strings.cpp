//===類似題===
416. Partition Equal Subset Sum
989. Add to Array-Form of Integer

//===思路====
1.先計算兩個string的大小, 可推得對應的index
2.從每一個陣列的最後一個index開始算起,每一個對應的元素相加
num1[m]+num2[n]+carray ; carry是前一次計算的進位值

3.每一次計算, m--,n--一直到m<0, n<0
//===
string helper0(string num1, string num2){
    int m = num1.size()-1;
    int n = num2.size()-1;
    int carry = 0;
    string res;

    while(m>=0 || n>=0){
        int valm = (m>=0)? (num1[m--]-'0'): 0;//在判斷中做--動作, 就可以隔開(m<0)的情況,不用其他判斷式
        int valn = (n>=0)? (num2[n--]-'0'): 0;
        int sum = valm+valn+carry;

//        res = res+to_string(sum%10);
        res = to_string(sum%10)+res;
        carry = sum/10;
    }
    if(carry) res = "1"+res;
    return res;
}

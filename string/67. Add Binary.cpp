//===類似題===
68. Text Justification
989. Add to Array-Form of Integer
//===思路===

//====
string helper(string a, string b){
    string res;
    int carry = 0;
    int m = a.size()-1;//maximum index of string a
    int n = b.size()-1;//maximum index of string b
    

    while(m>=0 || n>=0){
        int valm = m>=0?a[m--]-'0':0;
        int valn = n>=0?b[n--]-'0':0;
        int sum = valm + valn + carry;
        res = to_string(sum%2)+ res;
        carry = sum/2;
    }
    return (carry==1)?("1"+res):res;
}
string addBinary(string a, string b) {
        return helper(a, b);
}

//===類似題===
2232. Minimize Result by Adding Parentheses to Expression
1202. Smallest String With Swaps
2149. Rearrange Array Elements by Sign

//====思路
(*)將int num先轉換為string來做比較計算比較容易運算
1.將偶數,奇數分別取出放到priority_queue中
2.遍歷原String,若element是偶數, 就從priority_queue中取出來, 填入新的string中
3.遍歷原String,若element是奇數, 就從priority_queue中取出來, 填入新的string中
//===
int helper0(int num){
    string s = to_string(num);
    string res;
    priority_queue<char> odd;
    priority_queue<char> even;
    for(int i=0;i<s.size();i++){
        ((s[i]-'0')%2)?odd.push(s[i]):even.push(s[i]);
    }

    for(int i=0; i<s.size(); i++){
        if((s[i]-'0')%2){
            char t = odd.top();
            res+=t;
            odd.pop();
        }else{
            char t = even.top();
            res+=t;
            even.pop();
        }
    }
    return stoi(res);
}

int largestInteger(int num) {
        return helper0(num);
}

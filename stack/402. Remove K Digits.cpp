//===類似題====
403. Frog Jump
321. Create Maximum Number
738. Monotone Increasing Digits
1673. Find the Most Competitive Subsequence
//===思路====
(*)題目可以看成刪除k個數,使其排列是"升續"
(*)leading zero不算在 counter "k", 所以可以自由刪除.  
(*)類似155.Min Stack的概念 =>在stack中,只儲存比stk.top()小的數值
      402.Remove K Digits =>此題是stack中儲存比stk.top()大的數值, 若比stk.top()小,則刪除stk.top()
 
1.遍歷數列,當後[i] < [i-1];則要把前面那一個(i-1)數刪除
2.如果所有的數排列ascending, 則上述過程不發生; 跳出迴圈必須把最後k個數刪除
2.2 num="666777", k=3 =>最後遍歷完k=3,最後必須刪除777
2.3 num="177117", k=3 =>最後遍歷完k=1,所以必須把最後一個7刪除

3.遍歷條件 for 或 while
3.1 for是index會自動更新, while是index自己控制 

4. "解"從原本的數列去做調整 或 "解"透過新建得來  => 透過新建
4.1原本數列去做調整, 遍歷時index處理較困難

(*)tip:
-vector<int>可以當作stack使用
 v.push_back(a) , v.pop_back();


//======
string helper0(string num, int k){
    string res;
    int i=1;
    res.push_back(num[0]);
    
    for(int i=1; i<num.size(); i++){//loop{
        while(k>0 && res.size() && res.back()>num[i]){
            res.pop_back();//新建數列
            k--;
        }
        res.push_back(num[i]);
    }
    for(int i=0;i<k;i++) res.pop_back();//if all digits are ascending
    while(res[0]=='0') res.erase(res.begin());//count leading zero
    return (res=="")?"0":res;//if string is empty after removing. 
}

string removeKdigits(string num, int k) {
    return helper0(num,k);
}

//=======
string removeKdigits(string num, int k) {
        string ans="";
        for(auto ch: num){
            while(ans.size() && ans.back()>ch && k){
                ans.pop_back();
                k--;
            }
            if(ans.size() || ch!='0')
                ans+=ch;
        }
        while(ans.size() && k--){
            ans.pop_back();
        }
        return ans.size()==0?"0":ans;
}

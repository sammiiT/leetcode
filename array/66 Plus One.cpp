//===類似題===
67. Add Binary
369. Plus One Linked List
989. Add to Array-Form of Integer
//===思路===
(*)用vector或stack都可以計算此題
(*)考vector<int> 的insert函數
//=======
vector<int> plusOne(vector<int>& digits) {
    reverse(digits.begin(),digits.end());//先倒轉述列,比較好算
    vector<int> res;
    int carry = 0;
    for(int i=0;i<digits.size();i++){
        int sum = digits[i]+(i?carry:1);//如果是第0個,要加上1;不是第0個,加上carry
        carry = sum/10;
        sum = sum%10;
        res.insert(res.begin(),sum);
    }
    if(carry) res.insert(res.begin(),1);//如果最後有carray,還要將1插入陣列頭
    return res;
}

//===寫法2===
vector<int> plusOne(vector<int>& digits){
    int carry = 1;
    for(int i=digits.size()-1; i>=0; --i){//從最後一個element開始算, 個位數
        if(digits[i] + carry > 9){//有進位
            digits[i]=0;
            carry = 1;
        }else{//digits[i]+carry <= 9 沒有進位
            digits[i]+=carry;
            carry = 0;
        }
    }
    if(carry==1) digits.insert(digits.begin(),1);
    return digits;
}

//=====
class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits){
        stack<int> s;
        vector<int> res;
        int carry=1;
        
        for(int i=0; i<digits.size(); ++i){
            s.push(digits[i]);
        }
        
        while(!s.empty()){
            int val = s.top()+carry;
            res.insert(res.begin(),val%10);
            carry = val/10;
            s.pop();
        }
        if(carry) res.insert(res.begin(),1);
        return res;
    }
    
    
    
    vector<int> plusOne_OK(vector<int>& digits) {
        stack<int> s;
        vector<int> res;
        if(digits.empty()) return digits;
        
        for(int i=0;i<digits.size();++i){
            s.push(digits[i]);
        }
        
        int carry = 1;
        while(s.size()){
            res.push_back((s.top()+carry)%10);
            carry = (s.top()+carry)/10;
            s.pop();
        }
        if(carry==1) res.push_back(1);
        //sort(res.rend(),res.rbegin());
        reverse(res.begin(),res.end());
        return res;
    }
};

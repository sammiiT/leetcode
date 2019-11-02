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
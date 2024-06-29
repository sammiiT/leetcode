//===類似題===
156. Binary Tree Upside Down
239. Sliding Window Maximum
716. Max Stack

//===思路===
(*)兩stak, 定義 stk1和stk2; 
-stk1是依據推入順序推入
-stk2是存入minimum; 最上面(top)的數值, 是最小的值 

(*)stk2會排除其他min區間的數; 有min(x,y)的概念=>排除其他的數
1.如果用priority_queue會記錄到每一個數值, 求算起來

for(int i=0;i<nums;i++){
    res = min(res,nums[i]); //區間n~i 之間, 最小的數值
                            //res是0~n區間, 最小的數值
}
stk2的概念與min概念一樣: 
- stk2有紀錄每一個區間的最小數值, 
- min(x,y)是會排除前面區間最小的數值

(*)
數列[13,14,10,11,8,20,7]
stk1:
13,14,10,11,8,20,7

stk2: 只存比stk.top()小的數值
13,x ,10,x ,8,x ,7 => 13,10,8,7    

-getMin(),會直接從stk2中找top()
-top(),會從stk1中找top()
-pop(), 要從stk1中pop數值, 也要從stk2中pop數值(當stk2.top==stk1.top時);不做此動作,下次getMin會取到舊的數值.    
    
    
//=====
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if(stk2.empty() || stk2.top()>=val) stk2.push(val);
        stk1.push(val);
    }
    
    void pop() {
        if(stk2.top()==stk1.top()) stk2.pop();
        stk1.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
private:
    stack<int> stk1,stk2;
};

//===思路2===
(*) 建立一stack<int>, 紀錄stack的操作
(*) 建立一map<int,int>, 紀錄當下最小的數值

class MinStack{
public:
    MinStack(){}
    void push(int x){
        mp[x]++;
        stk.push(x);
    }    
    void pop(){
        int val = stk.top();
        mp[val]--;
        if(mp[val]==0) mp.erase(val);
        stk.pop();
    }
    int top(){
        return stk.top();    
    }
    int getMin(){
        map<int,int>::iterator it = mp.begin();
        return it->first;
    }
    
private:
map<int,int> mp;//value, count
stack<int> stk;
};


    

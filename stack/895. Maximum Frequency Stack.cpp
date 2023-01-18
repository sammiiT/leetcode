//===類似題===
896. Monotonic Array
433. Minimum Genetic Mutation
1257. Smallest Common Region
792. Number of Matching Subsequences

//===思路====
(*)將每一個數值的出現次數, 都建立一個stack;以 5,7,5,7,4,5為例
出現一次: 5,7,4   => 第一個vector<int>
出現兩次: 5,7     => 第二個vector<int>
出現三次: 5       => 第三個vector<int>
這三種情況,分別會記錄到 unordered_map<int,vector<int>> m;中
    
1 第一個pop, 找出現3次的5; pop完之後, 即不考慮出現三次的狀況,因為mxfreq會減1
2 第二個pop, 會找出現兩次的stack, 此stack有5和7, 因為7比較靠近top, 所以會先取得7
3 pop完之後, 第二個stack會剩下1個element, 直到5也被pop, 才不會被討論, mxfreq再減1
3.3 每次pop完一個數值之後, 都要對其次數減1, 此資訊存在於另外一個map中


//=======
class FreqStack {
public:
    FreqStack() {}
    void push(int val) {
        mxfreq = max(mxfreq, ++freq[val]);//紀錄每一個數字出現的次數,且找出最大的frequency
        m[freq[val]].push_back(val);//將每一種出現次數,都以陣列的方式,加入map中
    }
    int pop() {
        int x = m[mxfreq].back();//找出"出現頻率最高"的數字
        m[mxfreq].pop_back();//將出現頻去最高且最靠近top的數字移除
        if(m[mxfreq].empty()) mxfreq--; //如果最高頻率的數字都已經pop完, 則將最高頻率mxfreq減1
        freq[x]--;//將對應的數值的出現次數減1
        return x;//回傳
    }
  
private:
  int mxfreq;//出現的最多次數
  unordered_map<int,int> freq;//num, frequency; 數值出現的次數
  unordered_map<int,vector<int>> m;//frequency, nums vector(push as a vector);
                                   //每一種次數對應的數字;以陣列表示
};

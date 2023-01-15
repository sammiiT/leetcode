//===類似題===
896. Monotonic Array
433. Minimum Genetic Mutation
1257. Smallest Common Region
792. Number of Matching Subsequences
//===思路====


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


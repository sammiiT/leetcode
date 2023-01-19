//===類似題===
519. Random Flip Matrix
398. Random Pick Index
710. Random Pick with Blacklist
497. Random Point in Non-overlapping Rectangles
//===思路====
1. w的每一個元素,代表其出現的權重;如{7,6}
選到index = 0,有7/13的機率, 選到index = 1的機率有 6/13

2.設計一陣列,其陣列的元素,就是w每一個元素的累加  
- sum = {7,13}  => 13就是(7+6)
- 上面sum代表, 如果任意取一個數值,會出現"0~6"的機率和"7~12"的機率分別是7/13和6/13
- 而且, sum數列是有序的,所以可以用upper_bound

3.選擇數目 rand()%(sum.back()); sum.back()是總數
-當取到的數落在 sum的某個區間(upper_bound), 則回傳對應的idx
- 取到7~12,代表取到 w的 index=1的元素
-此時回傳index即可

4. 取到0~6,其upper_bound就是7,對應的index就是0, 也對應在w的index 0
   取到7~12,其upper_bound就是13,對應的index就是1, 同時也對應w的index 1

//=======
class Solution {
public:
    Solution(vector<int>& w) {
        int s = 0;
        for(int i=0; i<w.size(); i++){
            s = s+w[i];
            sum.push_back(s);
        }
        n = sum.back();
    }
    
    int pickIndex() {
        int t = rand()%n;
        int idx = upper_bound(sum.begin(),sum.end(),t)-sum.begin();
        return idx;       
    }
private:
    int n;
    vector<int> sum;    
};

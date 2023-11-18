//===類似題===
335. Self Crossing
991. Broken Calculator
843. Guess the Word
//===思路====
(*)計算四邊是否相等
(*)計算對角線是否相等
- 上述只會有兩個數字
- 如果出現0, 表示兩點重和
(*)用set來計算

long d(vector<int>& a,vector<int>& b){
    return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    unordered_set<long> s{d(p1,p2),d(p1,p3),d(p1,p4),d(p2,p3),d(p2,p4),d(p3,p4)};
    return !s.count(0)&&(s.size()==2);
}

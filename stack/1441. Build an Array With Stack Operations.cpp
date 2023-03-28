//===類似題===
1442. Count Triplets That Can Form Two Arrays of Equal XOR
2187. Minimum Time to Complete Trips
944. Delete Columns to Make Sorted
719. Find K-th Smallest Pair Distance
//===思路===
stream of integer  [1:n]用  stack的操作方式產生陣列target
- 遇到相等, push
- 遇到不相等, push之後,再pop;更新stream數值, 一直到stream push的值等於target[i]
- 停止條件; 遍歷完數列到"最後一個"之後


//===
vector<string> buildArray(vector<int>& target, int n) {
    vector<string> res;
    int j = 1;
    for(int i=0; i<target.size(); ++i){
        while(j<=n && target[i]!=j){//遇到不相等, push之後,再pop ; 一直到push的值等於target[i]
            res.push_back("Push");
            res.push_back("Pop");
            ++j;//update stream的數值
        }
        res.push_back("Push");//當stream數值等於target[i];直接push
        ++j;//update stream的數值
    }
    return res;
}

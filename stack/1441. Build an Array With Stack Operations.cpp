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

//===思路2===
(*)前一個思路是以target.size()為遍歷依據,
   這一個思路是以n為遍歷依據

(*)遍歷數列從1~n
-push_back 當下的數字到陣列中(此陣列會跟target陣列比較); 同時也加入"push"至vector<string>中
-比較數字陣列與target陣列的元素;
--如果相同, 繼續往下一個數字遍歷
--如果不同, 將數字陣列的back()做pop,並vector<string>加入"Pop"

- 判斷數字陣列的大小是否等於target陣列大小
--如果相同, 則跳出迴圈
--如果不同, 則繼續往下一個數字做運算

vector<string> buildArray(vector<int>& target, int n){
    vector<int> nums;
    vector<string> res;
    for(int i=1; i<=n; ++i){
        nums.push_back(i);
        res.push_back("Push");
        if(nums.back()!=target[nums.size()-1]){
            nums.pop_back();
            res.push_back("Pop");
        }
        if(nums.size()==target.size()) break;
    }
    return res;
}


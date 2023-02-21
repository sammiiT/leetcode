//===類似題====
1090. Largest Values From Labels
821. Shortest Distance to a Character
2369. Check if There is a Valid Partition For The Array
1981. Minimize the Difference Between Target and Chosen Elements

//===思路=====
(*)vector的操作
(*)erase()操作參數; 起始位址, 最後位址(最後位址不會被刪除, 是最後位址的前一個元素被刪除)
arr.erase(arr.begin()+5,arr.size()-1);//從index=5開始被刪除, arr.size()-1不會被刪除, 是arr.size()-2被刪除
arr.erase(arr.begin()+5,arr.end());//index=5開始被刪除, 到arr.size()-1 index

(*)erase是用iterator做運算

(*)遍歷數列方法; 依解題方向, 可用不同的遍歷方式
while(i<n){++i;}
for(int i=0;i<n;++i){}
for(auto a:arr){}
//=====
void helper0(vector<int>& arr){
    int n = arr.size();
    int i=0;
    while(i<n){
        if(arr[i]==0) {
            arr.insert(arr.begin()+i,0);//遇到0,插入0
            ++i;//因為插入新的原素, 所以位移一個位置, 此位置是原來的0(被擠壓到後一位)
        }
        ++i;//移到新元素的位址
    }
    arr.erase(arr.begin()+n,arr.end());
}

void helper1(vector<int>& arr){
  vector<int> res;
  for(int i=0;i<arr.size();i++){
    if(arr[i]==0){
      res.push_back(0);
      if(res.size()==arr.size()) break;
    }
    res.push_back(arr[i]);  
    if(res.size()==arr.size()) break;
  }
  arr = res;
}



void duplicateZeros(vector<int>& arr) {
    helper0(arr);      
}

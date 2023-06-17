//===類似題===
1. Two Sum
375. Guess Number Higher or Lower II
719. Find K-th Smallest Pair Distance
2239. Find Closest Number to Zero
//===思路===
(*) 左邊和右邊做差值比較
-左邊差值大,則移除左邊  (右邊比較接近x)
-右邊差值大,則移除右邊  (左邊比較接近x)
//=====
vector<int> findClosestElements(vector<int>& arr, int k, int x){
 //k = 個數
 //x = 接近的數值
  vector<int> res = arr;
  while(res.size()>k){//size = k的時候就是解
    if(abs(res.front()-x) <=abs(res.back()-x)) res.pop_back();//左邊比較接近x, 右邊移除
    else res.erase(res.begin());////右邊比較接近x, 移除左邊
  }
  return res;
}

//===思路2===
(*)比較差值, 將插值較小的push至priority_queue中
- 比較小的差值放在top
- 如果差值相等,則依照位置作排列, 位置越小排top

(*)得到priority_queue之後
-依照arr的實際大小,作排列
int i = lower_bound(res.begin(),res.end(),arr[p.second])-res.begin();
res.insert(res.begin()+i,arr[p.second]);

//=====
struct cmp{
bool operator()(pair<int,int>&a,pair<int,int>& b){
    if(a.first>b.first) return true;
    else if(a.first==b.first) return (a.second>b.second);  
    else return false;
}
};
vector<int> findClosestElements(vector<int>& arr, int k, int x){
    vector<int> res;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    for(int i=0;i<arr.size();++i){
        pair<int,int> p = {abs(arr[i]-x),i};
        pq.push(p);
    }
    while(k){
        pair<int,int> p = pq.top(); pq.pop();
        int i = lower_bound(res.begin(),res.end(),arr[p.second])-res.begin();
        res.insert(res.begin()+i,arr[p.second]);
        --k;
    }
    return res;
}

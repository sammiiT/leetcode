//===STL container 常用操作====


//=== set ===  

//=== multiset ===
<set>函式庫中非常有用的類型, 
-他可以當成一序列, 插入一個數,刪除一個數都能在O(logn)的時間內完成, 
-而且能時刻保證序列中的數是有序的,
-而且序列中可以存在重複的數

搜尋方法(method):
.count(elem) => 回傳elem的個數
.find(elem)  => 回傳elem的第一個元素 
.lower_bound(elem) =>回傳>=elem的第一個iterator
.upper_bound(elem) =>回傳>elem的第一個iterator
.equal_range(elem) =>回傳==elem的區間
  
 //=== unordered_set ====

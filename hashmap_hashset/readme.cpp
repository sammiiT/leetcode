//===STL container 常用操作====

//====map<key,value>===
(*)會自動依照key的大小排序; acesnding


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

int main(){   
    multiset<int> st;
    st.insert(7);
    st.insert(4);
    st.insert(3);
    st.insert(9);
    st.insert(8);
    for(multiset<int>::iterator it = st.begin(); it!=st.end(); it++){
        cout<<*it<<" ";
    } cout<<endl;
    
    pair<multiset<int>::iterator,multiset<int>::iterator> ret = st.equal_range(3);//回傳一個iterator的pair, first是初始位置,second的位址是最後一個的下一個
   
    cout<<*(ret.first)<<" "<<*(ret.second)<<endl; //3,4 ; 4是最後一個的下一個
//    st.erase(ret.first);
    st.erase(ret.first,ret.second);
    
    while(!st.empty()){
        cout<<*st.begin()<<" ";
        st.erase(st.begin());
    }cout<<endl;
    cout<<st.size()<<endl;
    return 0;
}

int main ()
{
  int myints[]= {77,30,16,2,30,30};
  std::multiset<int> mymultiset(myints, myints+6); // 2 16 30 30 30 77
/*
+6 是把end()也考慮進去
77,  30,  16,  2,  30,  30 ,   x   
^                              ^  
|---myints                     |---end(); 就是myints+6的位置
*/                                                    
                                                    
  std::pair<It,It> ret = mymultiset.equal_range(30); //2 16 30 30 30 77      
                                                     //      ^        ^
                                                     //      first    seconde                            
}
//=== unordered_set ====

//===STL container 常用操作====

/**********************
*      map<key,value>
***********************/
(*)會自動依照key的大小排序; acesnding

-宣告constructor:
map<char,int> mp;

-插入:insert()
mp.insert({'c',1});
mp.insert(pair<char,int>('a',3));
mp['b']=2;

-刪除:erase()
mp.erase('c');
    
-遍歷:
for(auto it:mp){
    cout<<"char="<<it.first<<" number="<<it.second<<endl;
}

for(map<char,int>::iterator it = mp.begin(); it!=mp.end(); ++it){
    cout<<"char="<<(*it).first<<" number = "<<(*it).second<<endl;
}

-元素判斷:
mp.count('b');
mp.find('b');

-元素清空:clear()
map.clear();

-判斷是否為空:empty()
if(mp.empty())

/***************************
*    set
****************************/
(*)set容器內的元素是唯一的,不重複
(*)set容器內的元素是有排序的
(*)set容器內的元素值不可以修改 
(*)set容器內的元素可以插入,或刪除

-set宣告 constructor:
set<int> st;

-set插入元素: insert()
st.insert(1);
st.insert(3);

-set刪除元素: erase()
st.erase(3);//刪除數值
st.earse(iterator);//從iterator刪除
    
-set清空元素: clear()
st.clear();
    
-set遍歷元素;
--遍歷時會依序排列
for(auto &s: myset){ cout<< s <<" "; }
for(set<int>::iterator it = st.begin(); it!=st.end(); ++it){
    cout<<*it<<" ";//iterator是一個指標
}

-set元素判斷:
st.count(1);//存在回傳1,不存在回傳0; 同map操作
st.find(1);//存在回傳iterator,不存在回傳end(); 同map操作

-set容器是否為空:
st.empty();

(*)set有upper_bound和lower_bound操作;回傳iterator
itu = st.upper_bound(5);
itl = st.lower_bound(3);

(*)set也有如priority_queue的class compare 函式    
struct cmp{//要加入const, 才可以用class compare
    bool operator()(const string& a,const string& b) const{
//        return a.size()<b.size();//錯誤, 會比對不到相等的情況; rat, cat=> rat會被排除
        return a.size()<=b.size();//修正, 可正確執行
    }
};
vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
set<string,cmp> st(words.begin(),words.end());//會按照string長度,由小到大做排序




/***************************
*    multiset
****************************/
multiset<class T>
-序列中可以存在重複的數
-能時刻保證序列中的數是有序的,
-他可以當成一序列, 插入一個數,刪除一個數都能在O(logn)的時間內完成, 

-multiset刪除元素:    
mulst.erase(val);//刪除所有值=val的元素
mulst.erase(it);//刪除iterator
mulst.erase(st.find(val));//刪除第一個值為val的元素

-multiset判斷元素:
mulst.count(elem) => 回傳elem的個數
mulst.find(elem)  => 回傳elem的第一個元素的iterator;沒有則回傳end() 

-multiset搜尋:回傳iterator    
mulst.lower_bound(elem) =>回傳>=elem的第一個iterator
mulst.upper_bound(elem) =>回傳>elem的第一個iterator
mulst.equal_range(elem) =>回傳==elem的區間

-multiset的某一個數值的iterator
st.equal_range(elem).first //回傳pair<iterator,iterator>
first,就是lower_bound
second,就是upper_bound

    
//=== multiset<class T> 範例 ===
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

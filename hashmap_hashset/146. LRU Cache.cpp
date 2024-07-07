//===類似題===
147. Insertion Sort List
460. LFU Cache
588. Design In-Memory File System
604. Design Compressed String Iterator

//===思路====
(*) list 模擬 LRU cache
list可以push_front(), push_back(),erase(),back()
list還可以 splice; 剪list 插入list的任意位置

1.概念: list中最後一個位置, 就是最不常用到的cache,
每次對list做access(put,get) , 都把其對應的iterator放到list最前面
不用紀錄每一個key的使用次數, 有用到, 就把對應的iterator放在最前面; 最少用到的一定是在list的最後面

2.定義list<pair<int,int>>//key, value

3.定義unordered_map,紀錄key和list的iterator
unordered_map<int,list<pair<int,int>>::iterator>//key, list的iterator

(*)
splice的iterator參數,經移動過後, 就會失效invalid

//========
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        auto it = m.find(key);
        if(it==m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    void put(int key, int value) {
        auto it = m.find(key);
        if(it!=m.end()) l.erase(it->second);//remove for update
        l.push_front(make_pair(key,value));
        m[key]=l.begin();
        if(m.size()>cap){
            int k = l.back().first;//最後一個元素
            //int k = l.rbegin()->first;//最後一個元素
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int,int>> l;//cache
    unordered_map<int,list<pair<int,int>>::iterator> m; //key, interator from "l"
};

//===小修正===
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it==m.end()) return -1;
        
        _cache.splice(_cache.begin(),//3.放到_cache的第一個位置
                        _cache,//1.從_cahce中
                        it->second);//2.剪下_cache的某一個iterator
        return _cache.begin()->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it!=m.end()) _cache.erase(it->second);
        _cache.push_front(make_pair(key,value));
        m[key]=_cache.begin();

        if(m.size()>_capacity){
            m.erase(_cache.back().first);//將key所對應的value從map中移除, 不是"刪除"
            _cache.pop_back();//將list中的最後一個"物件"刪除
        }    
    }

private:
int _capacity;
list<pair<int,int>> _cache;//<key,value>
unordered_map<int,list<pair<int,int>>::iterator> m;

};



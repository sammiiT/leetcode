//===more challenge===
381. Insert Delete GetRandom O(1) - Duplicates allowed
//===思路1====
(*)利用multiset

(*)題意:
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise
所以要remove所有的重複item
  
class RandomizedSet {
public:
    RandomizedSet() {      
    }
    
    bool insert(int val) {
        bool ret = mst.count(val)?0:1;
        mst.insert(val);
        return ret;
    }
    
    bool remove(int val) {
        bool ret = mst.count(val)?1:0;    
        //if(ret) mst.erase(mst.equal_range(val).first);
        if(ret) mst.erase(val);//remove所有的 val
        return ret;
    }
    
    int getRandom() {
        int i = rand()%mst.size();
        multiset<int>::iterator it=mst.begin();
        for(;i>0;--i){ ++it;  }
        return *it;
    }
private:
multiset<int> mst;
};

//===思路2=== FAILED
(*)利用uordered_map<int,int> //
(*)取餘數是0-index, 不是count
(rand()%total)是0-index, 
  
class RandomizedSet {
public:
    RandomizedSet() {      
      total = 0;
    }
    
    bool insert(int val) {
        bool ret = ump.count(val)?0:1;
        ump[val]++;
        total++;
        return ret;
    }
    
    bool remove(int val) {
        bool ret = ump.count(val)?1:0;
        if(ret) {
          total-=ump[val];
          ump.erase(val);
        }
        return ret;
    }
    
    int getRandom() {
        int i = rand()%total;//取餘數是0-index
        int j = 0;//j是count,不是index; 
        int ret = 0;
        for(map<int,int>::iterator it=ump.begin(); it!=mp.end(); ++it){
            j+=it->second;
//            if(j>=i){//"等於"描述會FAILED
            if(j>i){
              ret = it->first;
              break;
            } 
        }
        return ret;
    }
private:
map<int,int> ump;
int total;
};


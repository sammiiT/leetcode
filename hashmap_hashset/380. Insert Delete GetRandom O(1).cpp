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

//=== 思路3 ====
(*)本題是考 如何將vector<int> 在O(1)時間內做任意位置的"insert"和"remove"
- 其中vector中的element是單一個
(*)利用map<int,int>, 可達成上述目標
map<int,int> mp;//<value,index> 紀錄 vector數值和對應的index
每次insert就把值push到vector<int>的最後一位, 並將對應關係記錄到map中

每次remove就把vector中的最後一個數值取出, 放置到被移除的element中;運算式如下
        -------<
      /          \ 
  O  O  O  O      O(last)
     \    
       >remove(val)

int last = nums.back();
mp[last] = mp[val];//last數值現在要移到val述職的位置
nums[mp[last]] = last;
nums.pop_back();//將最後一個位置移除
mp.erase(val);//將val從map中移除


class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool ret = false;
        if(mp.count(val)) return ret;
        nums.push_back(val);
        mp[val] = nums.size()-1;
        return true;

    }
    
    bool remove(int val) {
        bool ret = false;
        if(!mp.count(val)) return ret;

        int lastn = nums.back();
        mp[lastn] = mp[val];
        nums[mp[lastn]] = lastn;
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int _rand = rand()%nums.size();
        return nums[_rand];
    }
private:
map<int,int> mp;//<value,count>
vector<int> nums;
};




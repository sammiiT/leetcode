//===more challenge===
2955. Number of Same-End Substrings
480. Sliding Window Median
1452. People Whose List of Favorite Companies Is Not a Subset of Another List

//===思路===
(*)不能用hashset, 會 time limited exceeded
int getRandom() {
    int i = rand()%mst.size();
    multiset<int>::iterator it=mst.begin();
    for(;i>0;--i){ ++it;  }//這邊for迴圈 會time limited exceeded
    return *it;
}
  
(*)用hashmap

class RandomizedCollection {
public:
    RandomizedCollection() {
        total = 0;
    }
    
    bool insert(int val) {
        bool ret = mp.count(val)?0:1;
        mp[val]++;
        total++;
        return ret;    
    }
    
    bool remove(int val) {
        bool ret = mp.count(val)?1:0;
        if(ret) {
          --total;
          if(--mp[val]==0) mp.erase(val);
        }
        return ret;        
    }
    
    int getRandom() {
        int i = rand()%total;
        int j = 0; 
        int ret = 0;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
            j+=it->second;
            if(j>i){
              ret = it->first;
              break;
            } 
        }
        return ret;
    }

private:
map<int,int> mp;
int total;
};

//===思路2===
(*)好難, 再思考
class RandomizedSet {
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (m.count(val)) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;//紀錄 insert value出現的最後一個index
        return true;
    }

    bool remove(int val) {
        if (!m.count(val)) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
}

//===思路3===
(*) map<> 和 priority_quue<>
(*) priority_queue<> 預設是從"大排到小"
  
class RandomizedSet {
public:
    RandomizedSet() {}
    bool insert(int val) {
        bool ret = true;
        if(mp[val].empty()) { ret = true;
        }else{ ret = false;
        }
        nums.push_back(val);
        mp[val].push(nums.size()-1);
        return ret;
    }

    bool remove(int val) {
        if(mp[val].empty()) return false;
        int index = mp[val].top();
        mp[val].pop();

        //index for nums.back()
        if(index!=nums.size()-1){
            int tmp = nums.back();//
            nums[index]=tmp;
            mp[tmp].pop();//indx for nums.back(), and is going to be pop from nums
                           //priority_queue<> 預設是從"大排到小", 所以先將nums.back()的索引 pop();移除 
            mp[tmp].push(index);//new index for nums.back()
        }
        nums.pop_back();
    }

    int getRandom() {
        int _rand = rand()%nums.size();
        return nums[_rand];
    }
private:
    vector<int> nums;
    map<int,priority_queue<int>> mp;
}







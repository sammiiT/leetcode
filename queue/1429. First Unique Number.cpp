//===類似題====


//===思路===
(*)queue和map
1.add 紀錄每一個數出現的次數, 和出現的順序
2.pop Q中的每一個element, 如果滿足條件就回傳數值
3.不用管q.pop的數值, 因為被pop的數值都是不滿足條件的
//====
class FirstUnique{
public:
    FirstUnique(){}
    FirstUnique(vector<int> nums){
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            q.push(nums[i]);
        }
    }
    int showFirstUnique(){//不用管q.pop的數值, 因為被pop的數值都是不滿足條件的.
        while(!q.empty()){//pop Q中的每一個element, 如果滿足條件就回傳數值
            if(mp[q.front()]==1) return q.front();
            q.pop();
        }
        return -1; 
    }
    void add(int value){
        mp[value]++;
        q.push(value);
    }
private:
    unordered_map<int,int> mp;//紀錄每一個數,出現的次數
    queue<int> q;//紀錄陣列
};

//===思路2===
(*)vector和map
1. vector記錄每一個數值出現的位置
2. 定義2個map, 一個紀錄數字出現的次數; 一個紀錄first unique 出現的位置

//====
class FirstUnique{
public:
    FirstUnique(){}
    FirstUnique(vector<int> nums){
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                mp[nums[i]]++;
                uni.erase(nums[i]);
            }else{
                mp[nums[i]]++;
                uni[nums[i]]=i;
            }
            arr.push_back(nums[i]);
        }
    }
    int showFirstUnique(){//顯示first unique數值
        int res = INT_MAX;
        for(auto a:uni){//從unique first的map找出index最小的那一個
            res = min(res,a.second);
        }
        return res==INT_MAX?(-1):arr[res];//如果不存在, 回傳-1; 存在, 從記錄的陣列找出對應的數值
    }
    void add(int value){//推入數值
        if(mp.count(value)){
            mp[value]++;
            uni.erase(value);
        }else{//沒出現數值,mp和uni紀錄
            mp[value]++;
            uni[value]=arr.size();//每次新紀錄都是最後一個位置
        }
        arr.push_back(value);//紀錄順序
    }
private:
    unordered_map<int,int> mp;
    unordered_map<int,int> uni;//value, index
    vector<int> arr;
};

//測試
int main()
{
/*    FirstUnique firstUnique = FirstUnique({7,7,7,7,7,7});
    cout<<firstUnique.showFirstUnique()<<endl;    
    firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
    firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
    firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
    firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
    firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
    cout<<firstUnique.showFirstUnique()<<endl;*/
 
  FirstUnique firstUnique = FirstUnique({809});
  cout<<firstUnique.showFirstUnique()<<endl; // return 809
  firstUnique.add(809);          // the queue is now [809,809]
  cout<<firstUnique.showFirstUnique()<<endl; // return -1 
  return 0;
}


